#ifndef _8591CD52_1418_4505_BBC0_CF2A7A3D3CF4_
#define _8591CD52_1418_4505_BBC0_CF2A7A3D3CF4_

#if ATSAM4N_SERIES 
#  include "./atsam4/atsam4n/include/atsam4n.h"
#elif ATSAM4S_SERIES 
#  include "./atsam4/atsam4s/include/atsam4s.h"
#elif ATSAM4E_SERIES 
#  include "./atsam4/atsam4e/include/atsam4e.h"
#else /* ATSAM4E_SERIES */
#  error "no device selected"
#endif

#endif /* _8591CD52_1418_4505_BBC0_CF2A7A3D3CF4_ */
