#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>
#include "cxyz.h"

class cTriangle
{
public:
    std::vector<cxyz> myP;

    bool operator==(const cTriangle &other) const
    {
        return (
            myP[0] == other.myP[0] &&
            myP[1] == other.myP[1] &&
            myP[2] == other.myP[2]);
    }
};

class cBuild
{
public:
    std::vector<cTriangle> myTriangles;       // all the triangles
    std::vector<cTriangle> mySelectTriangles; // triangles selected for hull

    /// @brief Add triangle to building
    /// @param t tiangle
    void add(const cTriangle &t)
    {
        myTriangles.push_back(t);
    }

    /// @brief add triangle to building
    /// @param vp traingle points
    void add( const std::vector<cxyz>& vp )
    {
        cTriangle t;
        t.myP = vp;
        add( t );
    }
    
    /// @brief select hull around air point
    /// @param ap air point
    void selectHull(cxyz ap);

    static bool unitTest();

private:
    std::vector<cxyz> destRays(cxyz ap);
};
