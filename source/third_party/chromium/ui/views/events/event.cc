// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ui/views/events/event.h"

#include "ui/views/view.h"

namespace ui {

////////////////////////////////////////////////////////////////////////////////
// Event, protected:

Event::Event(EventType type, int flags)
    : type_(type),
      flags_(flags) {
}

int Event::GetModifiers() const {
  int modifiers = 0;
  if (IsShiftDown())
    modifiers |= VKEY_SHIFT;
  if (IsControlDown())
    modifiers |= VKEY_CONTROL;
  if (IsAltDown())
    modifiers |= VKEY_MENU;
  if (IsCapsLockDown())
    modifiers |= VKEY_CAPITAL;
  return modifiers;
}

////////////////////////////////////////////////////////////////////////////////
// LocatedEvent, protected:

LocatedEvent::LocatedEvent(EventType type,
                           const gfx::Point& location,
                           int flags)
    : Event(type, flags),
      location_(location) {
}

LocatedEvent::LocatedEvent(const LocatedEvent& other,
                           View* source,
                           View* target)
    : Event(other.type(), other.flags()) {
  location_ = other.location();
  View::ConvertPointToView(*source, *target, &location_);
}

////////////////////////////////////////////////////////////////////////////////
// MouseEvent, public:

MouseEvent::MouseEvent(const ui::NativeEvent& native_event)
    : LocatedEvent(ui::EventTypeFromNative(native_event),
                   ui::EventLocationFromNative(native_event),
                   ui::EventFlagsFromNative(native_event)) {
}

MouseEvent::MouseEvent(const MouseEvent& other, View* source, View* target)
    : LocatedEvent(other, source, target) {
}

KeyEvent::KeyEvent(const ui::NativeEvent& native_event)
    : Event(ui::EventTypeFromNative(native_event),
            ui::EventFlagsFromNative(native_event)),
      key_code_(ui::KeyboardCodeFromNative(native_event)) {
}

MouseWheelEvent::MouseWheelEvent(const ui::NativeEvent& native_event)
    : LocatedEvent(ui::EventTypeFromNative(native_event),
                   ui::EventLocationFromNative(native_event),
                   ui::EventFlagsFromNative(native_event)),
      offset_(ui::GetMouseWheelOffset(native_event)) {
}

}  // namespace ui
