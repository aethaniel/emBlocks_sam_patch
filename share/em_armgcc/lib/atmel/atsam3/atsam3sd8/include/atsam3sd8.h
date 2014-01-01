#ifndef _7E4D4A58_4137_4C93_ABF6_B99CCDD2860D_
#define _7E4D4A58_4137_4C93_ABF6_B99CCDD2860D_

#if defined __ATSAM3SD8B__
  #include "atsam3sd8b.h"
#elif defined __ATSAM3SD8C__
  #include "atsam3sd8c.h"
#elif defined __ATSAM3S8B__
  #include "atsam3s8b.h"
#elif defined __ATSAM3S8C__
  #include "atsam3s8c.h"
#else
  #error Device not supported.
#endif

#endif /* _7E4D4A58_4137_4C93_ABF6_B99CCDD2860D_ */
