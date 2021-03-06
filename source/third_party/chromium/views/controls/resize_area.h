// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef VIEWS_CONTROLS_RESIZE_AREA_H_
#define VIEWS_CONTROLS_RESIZE_AREA_H_
#pragma once

#include <string>

#include "views/view.h"

namespace views {

class ResizeAreaDelegate;

////////////////////////////////////////////////////////////////////////////////
//
// An invisible area that acts like a horizontal resizer.
//
////////////////////////////////////////////////////////////////////////////////
class VIEWS_EXPORT ResizeArea : public View {
 public:
  static const char kViewClassName[];

  explicit ResizeArea(ResizeAreaDelegate* delegate);
  virtual ~ResizeArea();

  // Overridden from views::View:
  virtual std::string GetClassName() const OVERRIDE;
  virtual gfx::NativeCursor GetCursor(const views::MouseEvent& event) OVERRIDE;
  virtual bool OnMousePressed(const views::MouseEvent& event) OVERRIDE;
  virtual bool OnMouseDragged(const views::MouseEvent& event) OVERRIDE;
  virtual void OnMouseReleased(const views::MouseEvent& event) OVERRIDE;
  virtual void OnMouseCaptureLost() OVERRIDE;
  virtual void GetAccessibleState(ui::AccessibleViewState* state) OVERRIDE;

 private:
  // Report the amount the user resized by to the delegate, accounting for
  // directionality.
  void ReportResizeAmount(int resize_amount, bool last_update);

  // The delegate to notify when we have updates.
  ResizeAreaDelegate* delegate_;

  // The mouse position at start (in screen coordinates).
  int initial_position_;

  DISALLOW_COPY_AND_ASSIGN(ResizeArea);
};

}  // namespace views

#endif  // VIEWS_CONTROLS_RESIZE_AREA_H_
