

#include "GLU_color.hpp"

Color_t Color::make(u8 R, u8 G, u8 B){
#if   ( RH_CFG_GRAPHIC_COLOR_TYPE == RH_CFG_GRAPHIC_COLOR_BIN    )
    return MAKE_COLOR_1BIT(R,G,B);
#elif ( RH_CFG_GRAPHIC_COLOR_TYPE == RH_CFG_GRAPHIC_COLOR_RGB565 )
    return MAKE_COLOR_16BIT(R,G,B);
#elif ( RH_CFG_GRAPHIC_COLOR_TYPE == RH_CFG_GRAPHIC_COLOR_RGB888 )
    return MAKE_COLOR_24BIT(R,G,B);
#else
  #error
#endif
}

Color_t Color::lighten ( Color_t color    ){
    
#if   ( RH_CFG_GRAPHIC_COLOR_TYPE == RH_CFG_GRAPHIC_COLOR_BIN    )
    return MAKE_COLOR_1BIT(R,G,B);
#elif ( RH_CFG_GRAPHIC_COLOR_TYPE == RH_CFG_GRAPHIC_COLOR_RGB565 )
    return MAKE_COLOR_16BIT(R,G,B);
#elif ( RH_CFG_GRAPHIC_COLOR_TYPE == RH_CFG_GRAPHIC_COLOR_RGB888 )
    return 0;
#else
  #error
#endif
    
}

