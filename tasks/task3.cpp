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

    // TODO 1.1 Line

    // TODO 1.2 Face (triangle)

    // TODO 1.3 Surface mesh (cube)

    // TODO 2: Create a regular tetrahedron and a regular hexagon.
    // TODO 2.1 Regular tetrahedron

    // TODO 2.2 Regular hexagon


    polyscope::show();
}