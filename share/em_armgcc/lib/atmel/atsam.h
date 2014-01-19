 #ifndef _2568C584_9912_4820_9FB9_53FB83B3D885_
 #define _2568C584_9912_4820_9FB9_53FB83B3D885_

/*
 * ----------------------------------------------------------------------------
 * SAMD family
 * ----------------------------------------------------------------------------
 */

/* --- SAMD20 series --- */
#define ATSAMD20E ( (defined( __ATSAMD20E14__ )) || (defined( __ATSAMD20E15__ )) || (defined( __ATSAMD20E16__ )) || (defined( __ATSAMD20E17__ )) )
#define ATSAMD20G ( (defined( __ATSAMD20G14__ )) || (defined( __ATSAMD20G15__ )) || (defined( __ATSAMD20G16__ )) || (defined( __ATSAMD20G17__ )) || (defined( __ATSAMD20G18__ )) )
#define ATSAMD20J ( (defined( __ATSAMD20J14__ )) || (defined( __ATSAMD20J15__ )) || (defined( __ATSAMD20J16__ )) || (defined( __ATSAMD20J17__ )) || (defined( __ATSAMD20J18__ )) )
         
#define ATSAMD20_SERIES ( ATSAMD20E || ATSAMD20G || ATSAMD20J )

/* Full SAMD family */
#define ATSAMD_FAMILY ( ATSAMD20_SERIES )

/*
 * ----------------------------------------------------------------------------
 * SAM3 family
 * ----------------------------------------------------------------------------
 */

/* --- SAM3N series --- */
#define ATSAM3N00 ( (defined( __ATSAM3N00A__ )) || (defined( __ATSAM3N00B__ )) )
#define ATSAM3N0  ( (defined( __ATSAM3N0A__ )) || (defined( __ATSAM3N0B__ )) || (defined( __ATSAM3N0C__ )) )
#define ATSAM3N1  ( (defined( __ATSAM3N1A__ )) || (defined( __ATSAM3N1B__ )) || (defined( __ATSAM3N1C__ )) )
#define ATSAM3N2  ( (defined( __ATSAM3N2A__ )) || (defined( __ATSAM3N2B__ )) || (defined( __ATSAM3N2C__ )) )
#define ATSAM3N4  ( (defined( __ATSAM3N4A__ )) || (defined( __ATSAM3N4B__ )) || (defined( __ATSAM3N4C__ )) )

#define ATSAM3N_SERIES ( ATSAM3N00 || ATSAM3N0 || ATSAM3N1 || ATSAM3N2 || ATSAM3N4 )

/* --- SAM3S series --- */
#define ATSAM3S1   ( (defined( __ATSAM3S1A__ )) || (defined( __ATSAM3S1B__ )) || (defined( __ATSAM3S1C__ )) )
#define ATSAM3S2   ( (defined( __ATSAM3S2A__ )) || (defined( __ATSAM3S2B__ )) || (defined( __ATSAM3S2C__ )) )
#define ATSAM3S4   ( (defined( __ATSAM3S4A__ )) || (defined( __ATSAM3S4B__ )) || (defined( __ATSAM3S4C__ )) )
#define ATSAM3S8   ( (defined( __ATSAM3S8B__ )) || (defined( __ATSAM3S8C__ )) )
#define ATSAM3SD8  ( (defined( __ATSAM3SD8B__ )) || (defined( __ATSAM3SD8C__ )) )

#define ATSAM3S_SERIES ( ATSAM3S1 || ATSAM3S2 || ATSAM3S4 || ATSAM3S8 || ATSAM3SD8 )

/* --- SAM3U series --- */
#define ATSAM3U1   ( (defined( __ATSAM3U1C__ )) || (defined( __ATSAM3U1E__ )) )
#define ATSAM3U2   ( (defined( __ATSAM3U2C__ )) || (defined( __ATSAM3U2E__ )) )
#define ATSAM3U4   ( (defined( __ATSAM3U4C__ )) || (defined( __ATSAM3U4E__ )) )

#define ATSAM3U_SERIES ( ATSAM3U1 || ATSAM3U2 || ATSAM3U4 )

/* --- SAM3A series --- */
#define ATSAM3A4   ( (defined( __ATSAM3A4C__ )) )
#define ATSAM3A8   ( (defined( __ATSAM3A8C__ )) )

#define ATSAM3A_SERIES ( ATSAM3A4 || ATSAM3A8 )

/* --- SAM3X series --- */
#define ATSAM3X4   ( (defined( __ATSAM3X4C__ )) || (defined( __ATSAM3X4E__ )) )
#define ATSAM3X8   ( (defined( __ATSAM3X8C__ )) || (defined( __ATSAM3X8E__ )) )

#define ATSAM3X_SERIES ( ATSAM3X4 || ATSAM3X8 )

/* Full SAM3 family */
#define ATSAM3_FAMILY ( ATSAM3N_SERIES || ATSAM3S_SERIES || ATSAM3U_SERIES || ATSAM3X_SERIES || ATSAM3A_SERIES )

/*
 * ----------------------------------------------------------------------------
 * SAM4 family
 * ----------------------------------------------------------------------------
 */

/* --- SAM4N series --- */
#define ATSAM4N8   ( (defined( __ATSAM4N8A__ )) || (defined( __ATSAM4N8B__ )) || (defined( __ATSAM4N8C__ )) )
#define ATSAM4N16  ( (defined( __ATSAM4N16B__ )) || (defined( __ATSAM4N16C__ )) )

#define ATSAM4N_SERIES (ATSAM4N8 || ATSAM4N16)

/* --- SAM4S series --- */
#define ATSAM4S8   ( (defined( __ATSAM4S8B__ )) || (defined( __ATSAM4S8C__ )) )
#define ATSAM4S16  ( (defined( __ATSAM4S16B__ )) || (defined( __ATSAM4S16C__ )) )
#define ATSAM4SA16 ( (defined( __ATSAM4SA16B__ )) || (defined( __ATSAM4SA16C__ )) )
#define ATSAM4SD16 ( (defined( __ATSAM4SD16B__ )) || (defined( __ATSAM4SD16C__ )) )
#define ATSAM4SD32 ( (defined( __ATSAM4SD32B__ )) || (defined( __ATSAM4SD32C__ )) )

#define ATSAM4S_SERIES (ATSAM4S8 || ATSAM4S16 || ATSAM4S16 || ATSAM4SD16 || ATSAM4SD32)

/* --- SAM4E series --- */
#define ATSAM4E8   ( (defined( __ATSAM4E8C__ )) || (defined( __ATSAM4E8E__ )) )
#define ATSAM4E16  ( (defined( __ATSAM4E16C__ )) || (defined( __ATSAM4E16E__ )) )

#define ATSAM4E_SERIES (ATSAM4E8 || ATSAM4E16)

/* --- SAM4L series --- */
#define ATSAM4LC2 ( (defined( __ATSAM4LC2A__ )) || (defined( __ATSAM4LC2B__ )) || (defined( __ATSAM4LC2C__ )) ) 
#define ATSAM4LC4 ( (defined( __ATSAM4LC4A__ )) || (defined( __ATSAM4LC4B__ )) || (defined( __ATSAM4LC4C__ )) ) 
#define ATSAM4LC8 ( (defined( __ATSAM4LC8A__ )) || (defined( __ATSAM4LC8B__ )) || (defined( __ATSAM4LC8C__ )) ) 

#define ATSAM4LS2 ( (defined( __ATSAM4LS2A__ )) || (defined( __ATSAM4LS2B__ )) || (defined( __ATSAM4LS2C__ )) ) 
#define ATSAM4LS4 ( (defined( __ATSAM4LS4A__ )) || (defined( __ATSAM4LS4B__ )) || (defined( __ATSAM4LS4C__ )) ) 
#define ATSAM4LS8 ( (defined( __ATSAM4LS8A__ )) || (defined( __ATSAM4LS8B__ )) || (defined( __ATSAM4LS8C__ )) ) 

#define ATSAM4L_SERIES (ATSAM4LC2 || ATSAM4LC4 || ATSAM4LC8 || ATSAM4LS2 || ATSAM4LS4 || ATSAM4LS8)

/* Full SAM4 family */
#define ATSAM4_FAMILY ( ATSAM4N_SERIES || ATSAM4S_SERIES || ATSAM4E_SERIES || ATSAM4L_SERIES )

// Test/QA purpose only
//#define STR_HELPER(x) #x
//#define STR(x) STR_HELPER(x)
//#pragma message "content of ATSAM3_FAMILY = " STR(ATSAM3_FAMILY)
//#pragma message "content of ATSAM4_FAMILY = " STR(ATSAM4_FAMILY)

#if ATSAMD_FAMILY
#  include "atsamd.h"
#elif ATSAM3_FAMILY
#  include "atsam3.h"
#elif ATSAM4_FAMILY
#  include "atsam4.h"
#else
#  error "No Atmel device selected"
#endif

#endif /* _2568C584_9912_4820_9FB9_53FB83B3D885_ */
