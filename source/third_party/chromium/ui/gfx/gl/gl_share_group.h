// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_GFX_GL_GL_SHARE_GROUP_H_
#define UI_GFX_GL_GL_SHARE_GROUP_H_
#pragma once

#include <set>

#include "base/basictypes.h"
#include "base/memory/ref_counted.h"
#include "ui/gfx/gl/gl_export.h"

namespace gfx {

class GLContext;

// A group of GL contexts that share an ID namespace.
class GL_EXPORT GLShareGroup : public base::RefCounted<GLShareGroup> {
 public:
  GLShareGroup();

  // These two should only be called from the constructor and destructor of
  // GLContext.
  void AddContext(GLContext* context);
  void RemoveContext(GLContext* context);

  // Returns a handle to any initialized context in the share group or NULL if
  // there are no initialized contexts in the share group.
  void* GetHandle();

 private:
  friend class base::RefCounted<GLShareGroup>;
  ~GLShareGroup();

  // References to GLContext are by raw pointer to avoid a reference count
  // cycle.
  typedef std::set<GLContext*> ContextSet;
  ContextSet contexts_;
  DISALLOW_COPY_AND_ASSIGN(GLShareGroup);
};

}  // namespace gfx

#endif  // UI_GFX_GL_GL_SHARE_GROUP_H_
