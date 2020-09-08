/**
 ** The wx code base is littered with old-style code that fail to
 ** compile with our strict compiler warnings. Wrap wx #includes in this shim
 ** to ignore warnings only for that include.
 **/
#pragma once

#ifndef wxIMPLEMENT_WXWIN_MAIN

#ifdef __WXMAC__

#include <ApplicationServices/ApplicationServices.h>

#define wxIMPLEMENT_WXWIN_MAIN                                                \
    int main(int argc, char **argv)                                           \
    {                                                                         \
        wxDISABLE_DEBUG_SUPPORT();                                            \
                                                                              \
        ProcessSerialNumber psn = {0, kCurrentProcess};                       \
        TransformProcessType(&psn, kProcessTransformToForegroundApplication); \
        return wxEntry(argc, argv);                                           \
    }
#endif


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wdouble-promotion"
#include "wx/wx.h"
#pragma GCC diagnostic pop

