#pragma once

#include "Mesh.h"
#include "Material.h"
#include "Texture.h"
#include "Maths/Matrix4x4.hpp"
#include "Object.hpp"
#include "Camera.hpp"

class GameObject : public Object
{
    const Mesh* mesh;
    Material* material;
    Texture* texture;

public:
    float red;
    GameObject(Material* _material, const Mesh* _mesh, Texture* _texture = nullptr) {
        mesh = _mesh;
        material = _material;
        texture = _texture;
    }

    void render(Camera* camera) {
        material->use();
        
        int tintLocation = glGetUniformLocation(
            material->shaderProgram, "tintColor");
        glUniform4f(tintLocation, red, 0, 0, 1);
        
        
        Matrix4x4 model = calculateModelMatrix();
        unsigned int modelLoc = glGetUniformLocation(material->shaderProgram, "model");
        glUniformMatrix4fv(modelLoc, 1, GL_TRUE, &model.m11);
        
        Matrix4x4 view = camera->viewMatrix();
        unsigned int viewLoc = glGetUniformLocation(material->shaderProgram, "view");
        glUniformMatrix4fv(viewLoc, 1, GL_TRUE, &view.m11);
         
        Matrix4x4 projection = camera->projectionMatrix();
        unsigned int projectionLoc = glGetUniformLocation(material->shaderProgram, "projection");
        glUniformMatrix4fv(projectionLoc, 1, GL_TRUE, &projection.m11);
     
        
        int diffuseLocation = glGetUniformLocation(
            material->shaderProgram, "diffuseTexture");
        glUniform1i(diffuseLocation, 0);
        glActiveTexture(GL_TEXTURE0);
        if(texture != nullptr)
            glBindTexture(GL_TEXTURE_2D, texture->textureId);
        else
            glBindTexture(GL_TEXTURE_2D, 0);
        
        int blendLocation = glGetUniformLocation(
            material->shaderProgram, "blendTexture");
        glUniform1i(blendLocation, 1);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        
        mesh->render();
    }
};

// extend the triangle to have data members (fields)
//    - red, green, blue CHECK
//    - pass those data members to your uniform
// in your main function:
//    - pass in red color (1,0,0) for the first CHECK
//    - and green color (0,1,0) for the second CHECK

// result: one red, one green triangle
//         both using the same shader (like in Unity)

// if done early: play around with meshes
// can you make any polygon?
// triangle, square, pentagon, hexagon, ...
