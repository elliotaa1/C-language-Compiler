#ifndef COMPILERS_H_
#define COMPILERS_H_

#define DEBUG 0

/* Language name */
#define STR_LANGNAME "KeetsLang"

/* Logical constants - adapted for your language */
#define SPORTLANG_TRUE  1
#define SPORTLANG_FALSE 0

#define INVALID NULL
#define EOF_CHAR '\0'

/* Typedefs for language data types */
typedef char            keetslang_char;
typedef char*           keetslang_strg;
typedef int             keetslang_intg;
typedef float           keetslang_real;
typedef void            keetslang_void;

typedef unsigned char   keetslang_boln;
typedef unsigned char   keetslang_byte;

typedef long            keetslang_long;
typedef double          keetslang_doub;

/* Define compatibility aliases */
typedef keetslang_char    keets_char;
typedef keetslang_strg    keets_strg;
typedef keetslang_intg    keets_intg;
typedef keetslang_real    keets_real;
typedef keetslang_void    keets_void;
typedef keetslang_boln    keets_boln;
typedef keetslang_byte    keets_byte;
typedef keetslang_long    keets_long;
typedef keetslang_doub    keets_doub;

/* Program mode identifiers */
enum PROGRAMS {
    PGM_CDR = '1', // Coder
    PGM_RDR = '2', // Reader
    PGM_SCN = '3', // Scanner
    PGM_PSR = '4', // Parser
    PGM_WRT = '5'  // Writer
};

/* Main function declarations */
keets_intg main1Coder(keets_intg argc, keets_strg* argv);
keets_intg main2Reader(keets_intg argc, keets_strg* argv);
keets_intg main3Scanner(keets_intg argc, keets_strg* argv);

keets_void printLogo();
keets_void errorPrint(keets_strg fmt, ...);

#endif