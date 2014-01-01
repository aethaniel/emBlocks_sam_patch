#ifndef _3B50DDA0_FED8_4E61_9D80_81EF14756CA3_
#define _3B50DDA0_FED8_4E61_9D80_81EF14756CA3_

#if defined __ATSAM3X4C__
  #include "atsam3x4c.h"
#elif defined __ATSAM3X4E__
  #include "atsam3x4e.h"
#elif defined __ATSAM3X8C__
  #include "atsam3x8c.h"
#elif defined __ATSAM3X8E__
  #include "atsam3x8e.h"
#else
  #error Device not supported.
#endif

#endif /* _3B50DDA0_FED8_4E61_9D80_81EF14756CA3_ */
