//
// Created by Ria Sharma on 12/05/23.
//

#ifndef LIGHTSOFF_MOUSEEVENT_HPP
#define LIGHTSOFF_MOUSEEVENT_HPP

#include "threepp/threepp.hpp"
#include "mouseEvent.hpp"

using namespace threepp;

// MyMouseListener has been copied from threepp/examples/objects/decal.cpp

class MyMouseListener: public MouseListener {

public:
    Vector2 mouse{-Infinity<float>, -Infinity<float>};

    explicit MyMouseListener(Canvas& canvas): canvas(canvas) {}

    bool mouseClick() {
        if (mouseDown) {
            mouseDown = false;
            return true;
        } else {
            return false;
        }
    }

    void onMouseDown(int button, const Vector2& pos) override {
        if (button == 0) {// left mousebutton
            mouseDown = true;
        }
    }

    void onMouseMove(const Vector2& pos) override {
        updateMousePos(pos);
    }

private:
    Canvas& canvas;
    bool mouseDown = false;

    void updateMousePos(Vector2 pos) {
        auto& size = canvas.getSize();
        mouse.x = (pos.x / static_cast<float>(size.width)) * 2 - 1;
        mouse.y = -(pos.y / static_cast<float>(size.height)) * 2 + 1;
    }
};

#endif //LIGHTSOFF_MOUSEEVENT_HPP
