#ifndef _GLU_COLOR_HPP
#define _GLU_COLOR_HPP

#include "RH_common.h"
#include "RH_color.h"
#include "RH_config.h"

#if   ( RH_CFG_GRAPHIC_COLOR_TYPE == RH_CFG_GRAPHIC_COLOR_BIN    )
typedef uint8_t  Color_t;
#elif ( RH_CFG_GRAPHIC_COLOR_TYPE == RH_CFG_GRAPHIC_COLOR_RGB565 )
typedef uint16_t Color_t;
#elif ( RH_CFG_GRAPHIC_COLOR_TYPE == RH_CFG_GRAPHIC_COLOR_RGB888 )
typedef uint32_t Color_t;
#else
  
#endif


class Color{
    
public:
    static Color_t make    ( u8 R, u8 G, u8 B );
    static Color_t lighten ( Color_t color    );
    static Color_t darken  ( Color_t color    ); //
    
    static Color_t red;   //
    static Color_t green; //
    static Color_t blue;  //
    
};


#endif
