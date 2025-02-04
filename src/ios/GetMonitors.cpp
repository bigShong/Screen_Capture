#include "ScreenCapture.h"
#include "SCCommon.h"
#include <ApplicationServices/ApplicationServices.h>


namespace SL{
    namespace Screen_Capture{
        
        std::vector<std::shared_ptr<Monitor>> GetMonitors() {
            std::vector<std::shared_ptr<Monitor>> ret;
            std::vector<CGDirectDisplayID> displays;
            CGDisplayCount count=0;
            //get count
            CGGetActiveDisplayList(0, 0, &count);
            displays.resize(count);
    
            CGGetActiveDisplayList(count, displays.data(), &count);
            for(auto  i = 0; i < count; i++) {
                auto r = CGDisplayBounds(displays[i]);
    
                auto name = std::string("Monitor ") + std::to_string(displays[i]);
                ret.push_back(CreateMonitor(i, displays[i], int(r.size.height),int(r.size.width), int(r.origin.x), int(r.origin.y), name ));
            }
            return ret;

        }
    }
}
