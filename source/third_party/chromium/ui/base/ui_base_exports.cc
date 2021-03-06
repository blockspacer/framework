// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is for including headers that are not included in any other .cc
// files contained with the ui module.  We need to include these here so that
// linker will know to include the symbols, defined by these headers, in the
// resulting dynamic library (ui.dll).

#include "ui/base/models/accelerator.h"
#include "ui/base/models/table_model_observer.h"
