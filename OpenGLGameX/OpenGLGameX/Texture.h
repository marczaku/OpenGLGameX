#pragma once

#include "stb_image.h"
#include "glad/glad.h"

class Texture{
public:
    unsigned int textureId;
    Texture(const char* imagePath, int textureUnit){
        
        stbi_set_flip_vertically_on_load(true);
        
        int width, height, nrChannels;
        
        unsigned char* data = stbi_load(imagePath,
            &width, &height, &nrChannels, 0);
        int inputFormat = nrChannels == 3 ? GL_RGB : GL_RGBA;
        glGenTextures(1, &textureId);
        glActiveTexture(textureUnit);
        glBindTexture(GL_TEXTURE_2D, textureId);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width,
            height, 0, inputFormat, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(data);
    }
};
