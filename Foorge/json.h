#ifndef JSON_H
#define JSON_H

#include <QString>
#include "model.h"

/**
 *  @brief JSON header class  - This class is dedicated to having methods that allows the user to load and save the
 *  projects created on the Sprite Editor to file to their desired location
 *
 *  @authors: Victoria Yong, Norman Canning, Evan Blanchard, Jaibir Singh Sandhu
 *  @date: 4/1/2024
 */
class JSON
{
public:
    /**
     * @brief JSON - default constructor
     */
    JSON();

    /**
     * @brief load - Loads a JSON file containing animation frames and initializes a Model object with the data
     * @param model - model reference to be initialized with the given animation frames
     * @param fileName - name of file to load
     */
    static void load(Model& model, QString fileName);

    /**
     * @brief save - Saves animation frames from current project to a JSON file
     * @param model - model reference containing animation frames to be saved
     * @param fileName - name of file to be saved as
     */
    static void save(Model& model, QString fileName);

};


#endif // JSON_H
