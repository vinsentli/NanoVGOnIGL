// Copyright (c) 2025 vinsentli
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include "demo.h"
#include "perf.h"
#include <nanovg_igl.h>
#include <igl/IGL.h>
#include <nanovg.h>
#include <shell/shared/input/InputDispatcher.h>
#include <shell/shared/platform/Platform.h>
#include <shell/shared/renderSession/RenderSession.h>

namespace igl::shell {

class MouseListener : public IMouseListener {
 public:
  bool process(const MouseButtonEvent& event) override {
    return true;
  }
  bool process(const MouseMotionEvent& event) override {
    mouseX = event.x;
    mouseY = event.y;
    return true;
  }
  bool process(const MouseWheelEvent& event) override {
    return true;
  }

  int mouseX;
  int mouseY;
};

class TouchListener : public ITouchListener {
 public:
  bool process(const TouchEvent& event) override {
    touchX = event.x;
    touchY = event.y;
    return true;
  }

  int touchX;
  int touchY;
};

class NanovgSession : public RenderSession {
 public:
  explicit NanovgSession(std::shared_ptr<Platform> platform) : RenderSession(std::move(platform)) {}
  void initialize() noexcept override;
  void update(igl::SurfaceTextures surfaceTextures) noexcept override;
  void teardown() noexcept override;

 private:
  void drawNanovg(float framebuffferWidth,
                  float framebufferHeight,
                  std::shared_ptr<igl::IRenderCommandEncoder> command);
  int loadDemoData(NVGcontext* vg, DemoData* data);

 private:
  std::shared_ptr<ICommandQueue> commandQueue_;
  RenderPassDesc renderPass_;

  NVGcontext* nvgContext_ = nullptr;
  int times_ = 0;
  DemoData nvgDemoData_;

  std::shared_ptr<MouseListener> mouseListener_;
  std::shared_ptr<TouchListener> touchListener_;

  PerfGraph fps_, cpuGraph_, gpuGraph_;
};

} // namespace igl::shell
