



#include <iostream>

#include "RH_color.h"
#include "RH_common.h"
#include "RH_config.h"

#include "BLK_data.h"
//#include "BLK_dsp.h"
#include "BLK_lib.h"
#include "BLK_math.h"
#include "BLK_graphic.h"
#include "BLK_image.h"
#include "BLK_utility.h"
#include "BLK_time.h"


#include "GLU_glucoo.hpp"
#include "GLU_dev.hpp"
using namespace std;

int main(int argc, char const *argv[] ){
    
    Monitor();
    
    Rectangular card;
    
    card
    .color   ()
    .padding ()
    .cornerRadius(78)
    .show    ();
    
    
    Monitor::snapshot();
    
    
    
}





