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
#include "nanovg.h"
#include <igl/IGL.h>

namespace iglu::nanovg {

/*
 * Create flags
 */
enum NVGcreateFlags {
  /*
   * Flag indicating if geometry based anti-aliasing is used (may not be needed when using MSAA).
   */
  NVG_ANTIALIAS = 1 << 0,
  /*
   * Flag indicating if strokes should be drawn using stencil buffer.
   * The rendering will be a little slower, but path overlaps
   * (i.e. self-intersecting or sharp turns) will be drawn just once.
   */
  NVG_STENCIL_STROKES = 1 << 1,
  /*
   * Flag indicating if double buffering scheme is used.
   * Flag indicating that additional debug checks are done.
   */
  NVG_DEBUG = 1 << 2,
};

/*
 * These are additional flags on top of NVGimageFlags.
 */
enum NVGimageFlags {
  /*
   * Do not delete texture handle.
   */
  NVG_IMAGE_NODELETE = 1 << 16,
};

/*
 * Creates a new NanoVG context.  The `flags` should be combination of `NVGcreateFlags` above.
 */
NVGcontext* CreateContext(igl::IDevice* device, int flags);

/*
 * Set RenderCommandEncoder form outside.
 * @param matrix , use outside matrix, for example : vulkan preRotate matrix.
 */
void SetRenderCommandEncoder(NVGcontext* ctx,
                             igl::IFramebuffer* framebuffer,
                             igl::IRenderCommandEncoder*,
                             float* matrix);

/*
 * Deletes the specified NanoVG context.
 */
void DestroyContext(NVGcontext* ctx);

} // namespace iglu::nanovg
