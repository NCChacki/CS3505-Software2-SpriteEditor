#include "json.h"
#include <QJsonObject>
#include <QByteArray>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonDocument>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QLatin1String>


JSON::JSON() {}

void JSON::load(Model& model, QString fileName){
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QByteArray byteArr = file.readAll(); //entire doc

    //create JSONDoc with the read-in file
    QJsonDocument jsonDoc = QJsonDocument::fromJson(byteArr);

    QJsonObject jsonObj = jsonDoc.object();
    QJsonArray framesArr = jsonObj["Frames"].toArray(); //look for "Frames" key

    std::cout << "loaded Frame size: " << jsonObj["Model_Frame_Size"].toInt() << std::endl;
    model.resetModel(jsonObj["Model_Frame_Size"].toInt());
    model.animationFrames.clear();

    //iterate through framesArr to get each frame's pixel info
    for(int i = 0; i < framesArr.size(); i++)
    {
        QJsonObject frame = framesArr[i].toObject();
        //get size of each frame
        int size = frame["Size"].toInt();
        //get pixels of each frame
        QString pixelDataQString = frame["Pixels"].toString();
        QByteArray pixelDataQLatin1ByteArr = pixelDataQString.toLatin1();
        QByteArray pixelByteArr = QByteArray::fromBase64(pixelDataQLatin1ByteArr);

        //create frame object
        Frame f(size);
        //qDebug() << f.imageData.loadFromData(pixelByteArr);
        QImage image = QImage((uchar*)pixelByteArr.data(),size, size, QImage::Format_ARGB32);
        //do deep copy of image
        f.imageData = image.copy();

        //add to model's animationFrame
        model.animationFrames.push_back(f);
    }
    model.bringBackFramesAfterLoad();
}

void JSON::save(Model& model, QString fileName){
    QJsonObject jsonObj;
    QJsonDocument jsonDoc;
    QJsonArray jsonFrameArr;

    for(auto frame : model.animationFrames){

        //byteArray represents the whole image of each frame
        QByteArray byteArr = QByteArray::fromRawData((char*)frame.imageData.bits(), frame.imageData.sizeInBytes());

        QJsonObject frameObj;
        frameObj.insert("Size", frame.size);
        std::cout << "saving frame size : " << frame.size << std::endl;
        // QString pixelDataString = QString::fromStdString(byteArr.toStdString());
        frameObj.insert("Pixels", QLatin1String(byteArr.toBase64()));
        jsonFrameArr.append(frameObj);
    }

    jsonObj.insert("Model_Frame_Size", model.frameSize);
    std::cout << "saving with model frame size " << model.frameSize << std::endl;
    jsonObj.insert("Frames", jsonFrameArr);
    jsonDoc.setObject(jsonObj);

    //write to file
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    file.write(jsonDoc.toJson());
    file.close();
}
