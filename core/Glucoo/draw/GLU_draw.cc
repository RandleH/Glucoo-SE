

#include "GLU_glucoo.hpp"
#include "GLU_dev.hpp"

#include "BLK_graphic.h"
#include "BLK_image.h"


#define DEFAULT_PADDING  ( ( ((var)RH_CFG_SCREEN_WIDTH) + ((var)RH_CFG_SCREEN_HEIGHT) ) >> (6) )


Shape::Shape( void ){
    
}

E_Status_t Shape::show( void ){
    printf("Shape::show\n");
    return MAKE_ENUM( kStatus_Denied    );
}

Shape& Shape::padding(){
    return *this;
}




struct Info_Rectangular{
    __Area_t   area;
    content    padMethod;
    var        cornerRadius;
    
    //...//
};
typedef struct Info_Rectangular* pInfo_Rectangular;
#define RectangularInfo         ((pInfo_Rectangular)(this->_info))

#define LIMIT_RECTANGULAR_HORIZONTAL_AREA do{\
    RectangularInfo->area.xs = RH_LIMIT(RectangularInfo->area.xs, RectangularInfo->area.xs, (this->_area.xs+this->_area.w)/2);\
    RectangularInfo->area.w  = RH_LIMIT(RectangularInfo->area.w , 0, RectangularInfo->area.w);\
}while(0)

#define LIMIT_RECTANGULAR_VERTICAL_AREA do{\
    RectangularInfo->area.ys = RH_LIMIT(RectangularInfo->area.ys, RectangularInfo->area.ys, (this->_area.ys+this->_area.h)/2);\
    RectangularInfo->area.h  = RH_LIMIT(RectangularInfo->area.h , 0, RectangularInfo->area.h);\
}while(0)

#define LIMIT_RECTANGULAR_AREA  do{\
    LIMIT_RECTANGULAR_HORIZONTAL_AREA ;\
    LIMIT_RECTANGULAR_VERTICAL_AREA   ;\
}while(0)

Rectangular::Rectangular( void ){
    this->_area.xs = 0;
    this->_area.ys = 0;
    this->_area.w  = RH_CFG_SCREEN_WIDTH;
    this->_area.h  = RH_CFG_SCREEN_HEIGHT;
    this->_info    = new Info_Rectangular();
    RectangularInfo->area         = this->_area;
    RectangularInfo->padMethod    = M_GLU_Padding_all;
    RectangularInfo->cornerRadius = 0;
}

Rectangular& Rectangular::padding( void ){
    RectangularInfo->area.xs += DEFAULT_PADDING;
    RectangularInfo->area.ys += DEFAULT_PADDING;
    RectangularInfo->area.w  -= DEFAULT_PADDING<<1;
    RectangularInfo->area.h  -= DEFAULT_PADDING<<1;
    
    LIMIT_RECTANGULAR_AREA;
    
    RectangularInfo->padMethod = M_GLU_Padding_all;
    return *this;
}

Rectangular& Rectangular::padding(var pix){
    
    if(pix > this->_area.h && pix > this->_area.w){
        RectangularInfo->area.xs =  RectangularInfo->area.ys =  RectangularInfo->area.w =  RectangularInfo->area.h = 0;
        return *this;
    }
    
    if( RectangularInfo->padMethod & M_GLU_Padding_top ){
        RectangularInfo->area.ys += pix;
    }
    
    if( RectangularInfo->padMethod & M_GLU_Padding_bottom ){
        RectangularInfo->area.h  -= pix<<1;
    }
    
    if( RectangularInfo->padMethod & M_GLU_Padding_leading ){
        RectangularInfo->area.xs += pix;
    }
    
    if( RectangularInfo->padMethod & M_GLU_Padding_trailing ){
        RectangularInfo->area.w  -= pix<<1;
    }
    
    
    if( RectangularInfo->padMethod & M_GLU_Padding_vertical ){
        LIMIT_RECTANGULAR_VERTICAL_AREA;
    }
    
    if( RectangularInfo->padMethod & M_GLU_Padding_horizontal ){
        LIMIT_RECTANGULAR_HORIZONTAL_AREA;
    }
    
    return *this;
}

Rectangular& Rectangular::padding(var pix, content M_GLU_Padding_xxx){
    if( M_GLU_Padding_xxx > M_GLU_Padding_all) return *this;
    
    RectangularInfo->padMethod = M_GLU_Padding_xxx;
    
    return this->padding(pix);
}

Rectangular& Rectangular::cornerRadius(var radius){
    radius = RH_LIMIT( radius, 0, RectangularInfo->area.w/2);
    radius = RH_LIMIT( radius, 0, RectangularInfo->area.h/2);
    
    RectangularInfo->cornerRadius = radius;
    return *this;
}

Rectangular& Rectangular::color  (){
    return *this;
}

Rectangular& Rectangular::fill   (){
    return *this;
}

Rectangular& Rectangular::fill   (Color_t color){
    return *this;
}

Rectangular& Rectangular::stoke  (){
    return *this;
}

E_Status_t   Rectangular::show   (){
    printf("Rectangular::show\n");
    
    BLK_Graph_backupCache();
    
    if(RectangularInfo->cornerRadius == 0){
        BLK_Graph_EX_rect_fill        ( &RectangularInfo->area, Monitor::_gram, NULL);
    }else{
        BLK_Graph_set_penSize         (  RectangularInfo->cornerRadius);
        BLK_Graph_EX_rect_round_fill  ( &RectangularInfo->area, Monitor::_gram, NULL );
    }
    
    BLK_Graph_restoreCache();
    return MAKE_ENUM( kStatus_Denied    );
}

Rectangular::~Rectangular( void ){
    
}


#undef RectangularInfo






