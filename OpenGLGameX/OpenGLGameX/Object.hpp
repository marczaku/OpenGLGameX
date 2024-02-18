#pragma once

#include "Maths/Matrix4x4.hpp"

class Object
{
public:
    Vector3 position{};
    Vector3 rotation{};
    
    virtual void update(){
        
    }
    
    Matrix4x4 calculateModelMatrix(){
        return Matrix4x4::Translation(position) * Matrix4x4::Rotation(rotation);
    }
};
