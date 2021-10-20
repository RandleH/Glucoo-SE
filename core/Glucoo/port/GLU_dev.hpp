#ifndef _GLU_DEV_HPP
#define _GLU_DEV_HPP

#include "RH_common.h"
#include "RH_color.h"
#include "RH_config.h"
#include "GLU_glucoo.hpp"


class Monitor{
public:
    Monitor(void);
    Monitor(var w, var h, size_t layers, Color_t* gram);//
    
    static E_Status_t snapshot ( void );

friend class Shape;
friend class Rectangular;
    
private:
    static E_Status_t show     ( const __Area_t& area );//
    static E_Status_t fill     ( const __Area_t& area );//
    
    static void      *_gram;
};


#endif
