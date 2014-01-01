 #ifndef _2568C584_9912_4820_9FB9_53FB83B3D885_
 #define _2568C584_9912_4820_9FB9_53FB83B3D885_

/*
 * ----------------------------------------------------------------------------
 * SAM3 family
 * ----------------------------------------------------------------------------
 */

/* SAM3N series */
#define ATSAM3N00 ( (defined( __ATSAM3N00A__ )) || (defined( __ATSAM3N00B__ )) )
#define ATSAM3N0  ( (defined( __ATSAM3N0A__ )) || (defined( __ATSAM3N0B__ )) || (defined( __ATSAM3N0C__ )) )
#define ATSAM3N1  ( (defined( __ATSAM3N1A__ )) || (defined( __ATSAM3N1B__ )) || (defined( __ATSAM3N1C__ )) )
#define ATSAM3N2  ( (defined( __ATSAM3N2A__ )) || (defined( __ATSAM3N2B__ )) || (defined( __ATSAM3N2C__ )) )
#define ATSAM3N4  ( (defined( __ATSAM3N4A__ )) || (defined( __ATSAM3N4B__ )) || (defined( __ATSAM3N4C__ )) )

/* Entire SAM3N series */
#define ATSAM3N_SERIES ( ATSAM3N00 || ATSAM3N0 || ATSAM3N1 || ATSAM3N2 || ATSAM3N4 )

/* SAM3S series */
#define ATSAM3S1   ( (defined( __ATSAM3S1A__ )) || (defined( __ATSAM3S1B__ )) || (defined( __ATSAM3S1C__ )) )
#define ATSAM3S2   ( (defined( __ATSAM3S2A__ )) || (defined( __ATSAM3S2B__ )) || (defined( __ATSAM3S2C__ )) )
#define ATSAM3S4   ( (defined( __ATSAM3S4A__ )) || (defined( __ATSAM3S4B__ )) || (defined( __ATSAM3S4C__ )) )
#define ATSAM3S8   ( (defined( __ATSAM3S8B__ )) || (defined( __ATSAM3S8C__ )) )
#define ATSAM3SD8  ( (defined( __ATSAM3SD8B__ )) || (defined( __ATSAM3SD8C__ )) )

/* Entire SAM3N series */
#define ATSAM3S_SERIES ( ATSAM3S1 || ATSAM3S2 || ATSAM3S4 || ATSAM3S8 || ATSAM3SD8 )

/* SAM3U series */
#define ATSAM3U1   ( (defined( __ATSAM3U1C__ )) || (defined( __ATSAM3U1E__ )) )
#define ATSAM3U2   ( (defined( __ATSAM3U2C__ )) || (defined( __ATSAM3U2E__ )) )
#define ATSAM3U4   ( (defined( __ATSAM3U4C__ )) || (defined( __ATSAM3U4E__ )) )

/* Entire SAM3U series */
#define ATSAM3U_SERIES ( ATSAM3U1 || ATSAM3U2 || ATSAM3U4 )

/* SAM3A series */
#define ATSAM3A4   ( (defined( __ATSAM3A4C__ )) )
#define ATSAM3A8   ( (defined( __ATSAM3A8C__ )) )

/* Entire SAM3A series */
#define ATSAM3A_SERIES ( ATSAM3A4 || ATSAM3A8 )

/* SAM3X series */
#define ATSAM3X4   ( (defined( __ATSAM3X4C__ )) || (defined( __ATSAM3X4E__ )) )
#define ATSAM3X8   ( (defined( __ATSAM3X8C__ )) || (defined( __ATSAM3X8E__ )) )

/* Entire SAM3X series */
#define ATSAM3X_SERIES ( ATSAM3X4 || ATSAM3X8 )

/* Entire SAM3 family */
#define ATSAM3_FAMILY ( ATSAM3N_SERIES || ATSAM3S_SERIES || ATSAM3U_SERIES || ATSAM3X_SERIES || ATSAM3A_SERIES)

/*
 * ----------------------------------------------------------------------------
 * SAM4 family
 * ----------------------------------------------------------------------------
 */

/* SAM4N series */
#define ATSAM4N8   ( (defined( __ATSAM4N8A__ )) || (defined( __ATSAM4N8B__ )) || (defined( __ATSAM4N8C__ )) )
#define ATSAM4N16  ( (defined( __ATSAM4N16B__ )) || (defined( __ATSAM4N16C__ )) )

/* Entire SAM4N series */
#define ATSAM4N_SERIES (ATSAM4N8 || ATSAM4N16)

/* SAM4S series */
#define ATSAM4S8   ( (defined( __ATSAM4S8B__ )) || (defined( __ATSAM4S8C__ )) )
#define ATSAM4S16  ( (defined( __ATSAM4S16B__ )) || (defined( __ATSAM4S16C__ )) )
#define ATSAM4SA16 ( (defined( __ATSAM4SA16B__ )) || (defined( __ATSAM4SA16C__ )) )
#define ATSAM4SD16 ( (defined( __ATSAM4SD16B__ )) || (defined( __ATSAM4SD16C__ )) )
#define ATSAM4SD32 ( (defined( __ATSAM4SD32B__ )) || (defined( __ATSAM4SD32C__ )) )

/* Entire SAM4S series */
#define ATSAM4S_SERIES (ATSAM4S8 || ATSAM4S16 || ATSAM4S16 || ATSAM4SD16 || ATSAM4SD32)

/* SAM4E series */
#define ATSAM4E8   ( (defined( __ATSAM4E8C__ )) || (defined( __ATSAM4E8E__ )) )
#define ATSAM4E16  ( (defined( __ATSAM4E16C__ )) || (defined( __ATSAM4E16E__ )) )

/* Entire SAM4E series */
#define ATSAM4E_SERIES (ATSAM4E8 || ATSAM4E16)

/* Entire SAM4 family */
#define ATSAM4_FAMILY ( ATSAM4S_SERIES )

// Test/QA purpose only
//#define STR_HELPER(x) #x
//#define STR(x) STR_HELPER(x)
//#pragma message "content of ATSAM3_FAMILY = " STR(ATSAM3_FAMILY)
//#pragma message "content of ATSAM4_FAMILY = " STR(ATSAM4_FAMILY)

#if ATSAM3_FAMILY
#  include "atsam3.h"
#elif ATSAM4_FAMILY
#  include "atsam4.h"
#else
#  error "No Atmel device selected"
#endif

#endif /* _2568C584_9912_4820_9FB9_53FB83B3D885_ */
