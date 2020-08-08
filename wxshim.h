/**
 ** The wx code base is littered with old-style code that fail to
 ** compile with our strict compiler warnings. Wrap wx #includes in this shim
 ** to ignore warnings only for that include.
 **/
#pragma once

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wdouble-promotion"
#include "wx/wx.h"
#pragma GCC diagnostic pop

