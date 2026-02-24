#include "task3.h"

#include <array>
#include <vector>
#include <cmath>

#include "polyscope/polyscope.h"
#include "polyscope/point_cloud.h"
#include "polyscope/curve_network.h"
#include "polyscope/surface_mesh.h"


void task3() {
    polyscope::init();

    // Point
    std::vector<std::array<double, 3>> pointV = { {0.0, 0.0, 0.0} };
    auto* point = polyscope::registerPointCloud("point", pointV);
    point->setPointRadius(0.04);

    // TODO 1: Create at least:
    //   - one line using polyscope::registerCurveNetwork()
    //   - one triangle and one cube using polyscope::registerSurfaceMesh()
    //   Hints:
    //   - vertices: std::vector<std::array<double, 3>>
    //   - edges (for curve network): std::vector<std::array<int, 2>>
    //   - faces (for surface mesh):  std::vector<std::array<int, 3>>

    // Line
    std::vector<std::array<double, 3>> lineV = { {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0} };
    std::vector<std::array<int, 2>> lineE = { {0, 1} };
    auto* line = polyscope::registerCurveNetwork("line", lineV, lineE);

    // Face (triangle)
    std::vector<std::array<double, 3>> triV = {
        {0.0, 0.0, 0.0},
        {0.6, 0.0, 0.0},
        {0.0, 0.6, 0.0}
    };
    std::vector<std::array<int, 3>> triF = { {0, 1, 2} };
    auto* triangle = polyscope::registerSurfaceMesh("triangle", triV, triF);

    // Surface mesh (cube)
    std::vector<std::array<double, 3>> cubeV = {
        {0,0,0},{1,0,0},{1,1,0},{0,1,0},
        {0,0,1},{1,0,1},{1,1,1},{0,1,1}
    };
    std::vector<std::array<int, 3>> cubeF = {
        {0,1,2},{0,2,3},
        {4,5,6},{4,6,7},
        {0,1,5},{0,5,4},
        {2,3,7},{2,7,6},
        {1,2,6},{1,6,5},
        {0,3,7},{0,7,4}
    };
    auto* cube = polyscope::registerSurfaceMesh("cube", cubeV, cubeF);

    // TODO 2: Create a regular tetrahedron and a regular hexagon.

    // Regular tetrahedron
    std::vector<std::array<double, 3>> tetV = {
        {0.0, 0.0, 0.0},
        {1.0, 0.0, 0.0},
        {0.5, 0.0, std::sqrt(3.0) / 2.0},
        {0.5, std::sqrt(2.0 / 3.0), std::sqrt(3.0) / 6.0}
    };
    std::vector<std::array<int, 3>> tetF = {
        {0, 1, 2},
        {0, 1, 3},
        {1, 2, 3},
        {2, 0, 3}
    };

    auto* tetra = polyscope::registerSurfaceMesh("tetrahedron", tetV, tetF);
    tetra->setSurfaceColor({1.0, 0.7, 0.3});
    tetra->setPosition({-1.5, 0.0, 0.0});


    // Regular hexagon
    // Here the solution makes it by triangulating the polygon with a center plus 6 vertices on a circle. Feel free to make it in you way.
    double R = 0.6;
    std::vector<std::array<double, 3>> hexV;
    hexV.push_back({0.0, 0.0, 0.0});
    for (int k = 0; k < 6; k++) {
        double ang = (2.0 * M_PI * k) / 6.0;
        hexV.push_back({R * std::cos(ang), R * std::sin(ang), 0.0});
    }
    std::vector<std::array<int, 3>> hexF;
    for (int k = 1; k <= 6; k++) {
        int k2 = (k == 6) ? 1 : (k + 1);
        hexF.push_back({0, k, k2});
    }

    auto* hexagon = polyscope::registerSurfaceMesh("hexagon", hexV, hexF);
    hexagon->setSurfaceColor({0.4, 0.9, 0.6});
    hexagon->setPosition({1.5, 0.0, 0.0});


    polyscope::show();
}