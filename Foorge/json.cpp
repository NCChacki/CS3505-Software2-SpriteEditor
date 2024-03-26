#include "json.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonDocument>
#include <QFile>
#include <QString>


JSON::JSON() {}

void JSON::load(Model& model, QString fileName){
    //model.animationFrames
}

void JSON::save(Model& model, QString fileName){
    QJsonObject jsonObj;
    QJsonDocument jsonDoc;
    QJsonArray allPixels;

    for(auto frame : model.animationFrames){

        QJsonArray jsonArr;
        for(int i = 0; i < (frame.size * frame.size * 4); i++){
            QJsonValue jsonVal(frame.pixels[i]);
            jsonArr.append(jsonVal);
        }

        QJsonObject frameObj;
        frameObj.insert("Size", frame.size);
        frameObj.insert("Pixels", jsonArr);
        allPixels.append(frameObj);

    }

    jsonObj.insert("Frames", allPixels);
    jsonDoc.setObject(jsonObj);

    //write to file
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    file.write(jsonDoc.toJson());
    file.close();
}
