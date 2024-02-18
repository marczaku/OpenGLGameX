#pragma once
#include "Object.hpp"
#include "Window.h"

class Camera : public Object {
    Window* window;
public:
    Camera(Window* window) : window{window}, fieldOfViewDegrees{45}{}
    float fieldOfViewDegrees;
    
    virtual void update() {
        const float cameraSpeed = 0.05f; // adjust accordingly
        if (window->getKeyDown(KeyCode::W))
            position += cameraSpeed * calculateModelMatrix().Forward();
        if (window->getKeyDown(KeyCode::S))
            position -= cameraSpeed * calculateModelMatrix().Forward();
        if (window->getKeyDown(KeyCode::A))
            position -= cameraSpeed * calculateModelMatrix().Right();
        if (window->getKeyDown(KeyCode::D))
            position += cameraSpeed * calculateModelMatrix().Right();
    }
    
    float getAspectRatio(){
        return window->getWidth() / window->getHeight();
    }
    
    float fieldOfViewRadians(){
        return fieldOfViewDegrees / 360 * 2 * M_PI;
    }
    
    Matrix4x4 projectionMatrix(){
        return Matrix4x4::Perspective(fieldOfViewRadians(), getAspectRatio(), 0.1f, 100);
    }
    
    Matrix4x4 viewMatrix(){
        return calculateModelMatrix().Inverse();
    }
};
