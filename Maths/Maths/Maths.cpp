//
//  Maths.cpp
//  Maths
//
//  Created by Marc Zaku on 08.02.24.
//

#include <iostream>
#include "Maths.hpp"
#include "MathsPriv.hpp"

void Maths::HelloWorld(const char * s)
{
    MathsPriv *theObj = new MathsPriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void MathsPriv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};

