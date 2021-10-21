#include "GLU_dev.hpp"

#include "BLK_image.h"
#include "BLK_graphic.h"

void*      Monitor::_gram  ;



Monitor::Monitor(void){
    BLK_SRCT(Img888) *p = (BLK_SRCT(Img888)*)RH_MALLOC(sizeof(BLK_SRCT(Img888)));
    
    p->h   = RH_CFG_SCREEN_HEIGHT;
    p->w   = RH_CFG_SCREEN_WIDTH;
    p->ptr = (BLK_UION(Pixel888)*)RH_MALLOC(p->h*p->w*sizeof(Color_t));
    _gram = p;
    
    BLK_Graph_init();
#if   ( RH_CFG_GRAPHIC_COLOR_TYPE == RH_CFG_GRAPHIC_COLOR_BIN    )
    BLK_Graph_set_color_depth( kBLK_ColorDepth_1Bit );
#elif ( RH_CFG_GRAPHIC_COLOR_TYPE == RH_CFG_GRAPHIC_COLOR_RGB565 )
    BLK_Graph_set_color_depth( kBLK_ColorDepth_16Bit );
#elif ( RH_CFG_GRAPHIC_COLOR_TYPE == RH_CFG_GRAPHIC_COLOR_RGB888 )
    BLK_Graph_set_color_depth( kBLK_ColorDepth_24Bit );
#else
  
#endif
    
}


Monitor::Monitor(var w, var h, size_t layers, Color_t* gram){
    RH_ASSERT(0);
    _gram = gram;
}

#include <string>
E_Status_t Monitor::snapshot ( void ){
    
    std::string dir = RH_DIR;
    dir+= "snapshot.bmp";
    
#if   ( RH_CFG_GRAPHIC_COLOR_TYPE == RH_CFG_GRAPHIC_COLOR_BIN    )
    
#elif ( RH_CFG_GRAPHIC_COLOR_TYPE == RH_CFG_GRAPHIC_COLOR_RGB565 )
    
#elif ( RH_CFG_GRAPHIC_COLOR_TYPE == RH_CFG_GRAPHIC_COLOR_RGB888 )
    BLK_Img888_out_bmp( dir.c_str(), (const S_BLK_Img888_t *)_gram);
#else
    
#endif
    
    std::string cmd = "open "+dir;
    system(cmd.c_str());
    return MAKE_ENUM(kStatus_Success);
}








