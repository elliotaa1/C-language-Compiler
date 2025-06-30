/*
************************************************************
* COMPILERS COURSE - Algonquin College
* Code version: Summer, 2025
* Author: TO_DO
* Professors: Paulo Sousa
************************************************************
#
# ECHO "=---------------------------------------="
# ECHO "|  COMPILERS - ALGONQUIN COLLEGE (S25)  |"
# ECHO "=---------------------------------------="
# ECHO "    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    ”
# ECHO "    @@                             @@    ”
# ECHO "    @@           %&@@@@@@@@@@@     @@    ”
# ECHO "    @@       @%% (@@@@@@@@@  @     @@    ”
# ECHO "    @@      @& @   @ @       @     @@    ”
# ECHO "    @@     @ @ %  / /   @@@@@@     @@    ”
# ECHO "    @@      & @ @  @@              @@    ”
# ECHO "    @@       @/ @*@ @ @   @        @@    ”
# ECHO "    @@           @@@@  @@ @ @      @@    ”
# ECHO "    @@            /@@    @@@ @     @@    ”
# ECHO "    @@     @      / /     @@ @     @@    ”
# ECHO "    @@     @ @@   /@/   @@@ @      @@    ”
# ECHO "    @@     @@@@@@@@@@@@@@@         @@    ”
# ECHO "    @@                             @@    ”
# ECHO "    @@         K E E T S L A N G   @@    ”
# ECHO "    @@                             @@    ”
# ECHO "    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    ”
# ECHO "                                         "
# ECHO "[READER SCRIPT .........................]"
# ECHO "                                         "
*/

/*
************************************************************
* File name: Reader.h
* Compiler: MS Visual Studio 2022
* Course: CST 8152 – Compilers, Lab Section: [011, 012]
* Assignment: A12.
* Date: Jan 01 2025
* Professor: Paulo Sousa
* Purpose: This file is the main header for Reader (.h)
************************************************************
*/

/*
 *.............................................................................
 * MAIN ADVICE:
 * Please check the "TODO" labels to develop your activity.
 *.............................................................................
 */

#ifndef COMPILERS_H_
#include "Compilers.h"
#endif

#ifndef READER_H_
#define READER_H_

/* TIP: Do not change pragmas, unless necessary .......................................*/
/*#pragma warning(1:4001) *//*to enforce C89 type comments  - to make //comments an warning */

/* standard header files */
#include <stdio.h>  /* standard input/output */
#include <malloc.h> /* for dynamic memory allocation*/
#include <limits.h> /* implementation-defined data type ranges and limits */

/* CONSTANTS DEFINITION: GENERAL (NOT LANGUAGE DEPENDENT) .................................. */

/* Constants about controls (not need to change) */
#define READER_ERROR				(-1)	/* General error message */
#define READER_TERMINATOR			'\0'	/* General EOF */

/* CONSTANTS DEFINITION: PREFIXED BY LANGUAGE NAME .................................. */

/* TO_DO: You should add your own constant definitions here */
#define READER_MAX_SIZE	0				/* maximum capacity */ 

#define READER_DEFAULT_SIZE			250		/* default initial buffer reader capacity */

#define NCHAR				128			/* Chars from 0 to 127 */

#define CHARSEOF			(-1)		/* EOF Code for Reader */

#define keets_FALSE 0

#define keets_TRUE 1

/* STRUCTURES DEFINITION: SUFIXED BY LANGUAGE NAME .................................. */

/* TODO: Adjust datatypes */

/* Offset declaration */
typedef struct position {
	keets_intg read;			/* the offset to the get a char position (in chars) */
	keets_intg wrte;			/* the offset to the add chars (in chars) */
	keets_intg mark;			/* the offset to the mark position (in chars) */
} Position;


typedef struct flag {
	keets_boln isEmpty; /* checks if there is no content */
	keets_boln isFull; /* the content is using all size */
	keets_boln isRead; /* all content was read */
	keets_boln isMoved; /* the content was moved in reallocation */
} Flag;

/* Buffer structure */
typedef struct bufferReader {
	keets_strg		content;			/* pointer to the beginning of character array (character buffer) */
	keets_intg		size;				/* current dynamic memory size (in bytes) allocated to character buffer */
	Flag			flags;				/* contains character array reallocation flag and end-of-buffer flag */
	Position		position;			/* Offset / position field */
	keets_intg		histogram[NCHAR];	/* Statistics of chars */
	keets_intg		numReaderErrors;	/* Number of errors from Reader */
	keets_byte		checkSum;			/* Sum of bytes(chars) */
} Buffer, *BufferPointer;

/* FUNCTIONS DECLARATION:  .................................. */

/* General Operations */
BufferPointer	readerCreate		(keets_intg);
BufferPointer	readerAddChar		(BufferPointer const, keets_char);
keets_boln		readerClear		    (BufferPointer const);
keets_boln		readerFree		    (BufferPointer const);
keets_boln		readerIsFull		(BufferPointer const);
keets_boln		readerIsEmpty		(BufferPointer const);
keets_boln		readerSetMark		(BufferPointer const, keets_intg);
keets_intg		readerPrint		    (BufferPointer const);
keets_intg		readerLoad			(BufferPointer const, keets_strg);
keets_boln		readerRecover		(BufferPointer const);
keets_boln		readerRetract		(BufferPointer const);
keets_boln		readerRestore		(BufferPointer const);
keets_intg		readerChecksum		(BufferPointer const);
/* Getters */
keets_char		readerGetChar		(BufferPointer const);
keets_strg		readerGetContent	(BufferPointer const, keets_intg);
keets_intg		readerGetPosRead	(BufferPointer const);
keets_intg		readerGetPosWrte	(BufferPointer const);
keets_intg		readerGetPosMark	(BufferPointer const);
keets_intg		readerGetSize		(BufferPointer const);
keets_byte		readerGetFlags		(BufferPointer const);
keets_void		readerPrintStat		(BufferPointer const);
keets_intg		readerNumErrors		(BufferPointer const);

#endif
