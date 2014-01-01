#ifndef _840ED7B9_9F9B_4F37_8AC4_A55D71C742D0_
#define _840ED7B9_9F9B_4F37_8AC4_A55D71C742D0_

#if defined __ATSAM4N8A__
  #include "atsam4n8a.h"
#elif defined __ATSAM4N8B__
  #include "atsam4n8b.h"
#elif defined __ATSAM4N8C__
  #include "atsam4n8c.h"
#elif defined __ATSAM4N16B__
  #include "atsam4n16b.h"
#elif defined __ATSAM4N16C__
  #include "atsam4n16c.h"
#else
  #error Device not supported.
#endif

#endif /* _840ED7B9_9F9B_4F37_8AC4_A55D71C742D0_ */
