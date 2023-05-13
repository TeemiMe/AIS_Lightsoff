#include <iostream>
#include "gridMap.hpp"
#include "threepp/threepp.hpp"
#include <random>
#include "gridScene.hpp"
#include "mouseEvent.hpp"
#define LOG_INFO(msg) std::cout << "[INFO] " << msg << std::endl;

using namespace threepp;
using namespace std;

int main() {
   // BoxScene boxScene;
    //boxScene.run();
    auto scene = std::make_shared<BoxScene>();
    Canvas canvas;
    GLRenderer renderer(canvas);
    renderer.setClearColor(Color::black);


    /*int i,j;
    gridMap grid; // printing out after this line will print out the grid with values assigned 0
    grid.initializeGrid();// function for assigning 0 and 1 randomly
    grid.display();// printing out after this line will print out the grid with random assignments of 0 and 1
    std::cout << "Enter row and column (0-4) to toggle the light: ";

    while (cin >> i >> j) {
        grid.toggle(i, j);
        grid.display();
        grid.win();
    }*/
    MyMouseListener mouseListener(canvas);
    canvas.addMouseListener(&mouseListener);

    canvas.animate([&](float dt) -> void {
        std::cout<< mouseListener.mouseClick() << std::endl;
        renderer.render(scene.get(),
                        &scene->m_camera());
    });

}