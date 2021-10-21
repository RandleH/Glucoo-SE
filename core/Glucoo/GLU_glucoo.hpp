
#ifndef _GLU_GLUCOO_HPP
#define _GLU_GLUCOO_HPP

#include "RH_common.h"
#include "RH_color.h"
#include "RH_config.h"

#include "GLU_color.hpp"

typedef uint8_t content;
#define M_GLU_Align_leading          (1U)
#define M_GLU_Align_center           (2U)
#define M_GLU_Align_tailing          (3U)
#define M_GLU_Align_justifyed        (4U)
      
#define M_GLU_Padding_top            (1<<0)
#define M_GLU_Padding_bottom         (1<<1)
#define M_GLU_Padding_leading        (1<<2)
#define M_GLU_Padding_trailing       (1<<3)
#define M_GLU_Padding_vertical       (M_GLU_Padding_top|M_GLU_Padding_bottom)
#define M_GLU_Padding_horizontal     (M_GLU_Padding_leading|M_GLU_Padding_trailing)
#define M_GLU_Padding_all            (0x0f)



class Shape{
public:
    Shape( void );
    Shape( var w, var h );
    
    Shape& foo(void);
    
    virtual Shape&     padding ();
    virtual E_Status_t show    ();
protected:
    __Area_t _area;
private:
    
};


class Rectangular : public Shape{
public:
    Rectangular( void );
   ~Rectangular( void );
    
    Rectangular& padding          ( void );
    Rectangular& padding          (var pix);
    Rectangular& padding          (var pix, content M_GLU_Padding_xxx);//
    
    Rectangular& cornerRadius     (var radius);//
    
    Rectangular& color            (  );//
    
    Rectangular& fill             (void         );//
    Rectangular& fill             (Color_t color);//
    
    
    Rectangular& stoke            (  );//
    Rectangular& stoke            (var width);//
    
    E_Status_t   apply            (  );//
    E_Status_t   show             (  );//
protected:

private:
    void*        _info;
    
};


class Circle : public Shape{
    
};

#endif
