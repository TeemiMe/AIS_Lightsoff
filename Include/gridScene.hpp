
#ifndef LIGHTSOFF_GRIDSCENE_HPP
#define LIGHTSOFF_GRIDSCENE_HPP
#include <vector>
#include <random>
#include "mouseEvent.hpp"
#include "threepp/threepp.hpp"
using namespace threepp;

class BoxScene {
public:
    BoxScene();
    void run();
   // void checkWin();
   std::shared_ptr<Scene> m_scene;
   std::shared_ptr<OrthographicCamera> m_camera;

private:
    std::shared_ptr<BoxGeometry> m_geometry;
    std::shared_ptr<MeshBasicMaterial> m_material, m_whiteMaterial, m_yellowMaterial;
    std::vector<std::vector<std::shared_ptr<Mesh>>> m_boxes;
    std::random_device m_rd;
    std::mt19937 m_gen;
    std::uniform_int_distribution<> m_dis;
    std::shared_ptr<Mesh> mesh;
    Color color;


    void createBoxes();
    void changeBoxColors();
   // void animate();


};

#endif //LIGHTSOFF_GRIDSCENE_HPP
