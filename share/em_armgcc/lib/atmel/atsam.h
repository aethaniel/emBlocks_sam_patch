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

/* Entire SAM3 family */
#define ATSAM3_FAMILY (ATSAM3N_SERIES )

/*
 * ----------------------------------------------------------------------------
 * SAM4 family
 * ----------------------------------------------------------------------------
 */

/* SAM4S series */
#define ATSAM4S8   ( (defined( __ATSAM4S8B__ )) || (defined( __ATSAM4S8C__ )) )
#define ATSAM4S16  ( (defined( __ATSAM4S16B__ )) || (defined( __ATSAM4S16C__ )) )
#define ATSAM4SA16 ( (defined( __ATSAM4SA16B__ )) || (defined( __ATSAM4SA16C__ )) )
#define ATSAM4SD16 ( (defined( __ATSAM4SD16B__ )) || (defined( __ATSAM4SD16C__ )) )
#define ATSAM4SD32 ( (defined( __ATSAM4SD32B__ )) || (defined( __ATSAM4SD32C__ )) )


/* Entire SAM4S series */
#define ATSAM4S_SERIES (ATSAM4S8 || ATSAM4S16 || ATSAM4S16 || ATSAM4SD16 || ATSAM4SD32)


/* Entire SAM4 family */
#define ATSAM4_FAMILY ( ATSAM4S_SERIES )

//#define STR_HELPER(x) #x
//#define STR(x) STR_HELPER(x)
//#pragma message "content of ATSAM3_FAMILY = " STR(ATSAM3_FAMILY)

#if ATSAM3_FAMILY
#  include "atsam3.h"
#elif ATSAM4_FAMILY
#  include "atsam4.h"
#else
#  error "No Atmel device selected"
#endif

#endif /* _2568C584_9912_4820_9FB9_53FB83B3D885_ */
