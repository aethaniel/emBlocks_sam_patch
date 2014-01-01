#ifndef _F4639341_FFE5_4BD2_A3E0_93CC5B4EE40A_
#define _F4639341_FFE5_4BD2_A3E0_93CC5B4EE40A_

#if ATSAM3N_SERIES
#  include "./atsam3/atsam3n/include/atsam3n.h"
#elif ATSAM3S_SERIES
#  include "./atsam3/atsam3s/include/atsam3s.h"
#elif ATSAM3U_SERIES
#  include "./atsam3/atsam3u/include/atsam3u.h"
#elif ATSAM3A_SERIES
#  include "./atsam3/atsam3xa/include/atsam3a.h"
#elif ATSAM3X_SERIES
#  include "./atsam3/atsam3xa/include/atsam3x.h"
#else /* ATSAM3X_SERIES */
#  error "no device selected"
#endif

#endif /* _F4639341_FFE5_4BD2_A3E0_93CC5B4EE40A_ */
