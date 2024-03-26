#ifndef JSON_H
#define JSON_H

#include <QString>
#include "model.h"

class JSON
{
public:
    JSON();
    static void load(Model& model, QString fileName);
    static void save(Model& model, QString fileName);

private:

};





#endif // JSON_H
