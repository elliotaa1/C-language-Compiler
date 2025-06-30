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
# ECHO "    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    
# ECHO "    @@                             @@    
# ECHO "    @@           %&@@@@@@@@@@@     @@    
# ECHO "    @@       @%% (@@@@@@@@@  @     @@    
# ECHO "    @@      @& @   @ @       @     @@    
# ECHO "    @@     @ @ %  / /   @@@@@@     @@    
# ECHO "    @@      & @ @  @@              @@    
# ECHO "    @@       @/ @*@ @ @   @        @@    
# ECHO "    @@           @@@@  @@ @ @      @@    
# ECHO "    @@            /@@    @@@ @     @@    
# ECHO "    @@     @      / /     @@ @     @@    
# ECHO "    @@     @ @@   /@/   @@@ @      @@    
# ECHO "    @@     @@@@@@@@@@@@@@@         @@    
# ECHO "    @@                             @@    
# ECHO "    @@      K E E T S L A N G      @@    �
# ECHO "    @@                             @@
# ECHO "    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    
# ECHO "                                         "
# ECHO "[CODER SCRIPT ..........................]"
# ECHO "                                         "
*/

/*
************************************************************
* File name: MainCoder.c
* Compiler: MS Visual Studio 2022
* Course: CST 8152  Compilers, Lab Section: [011, 012]
* Assignment: A12, A22, A32.
* Date: Jan 01 2025
* Professor: Paulo Sousa
* Purpose: This file is the main code for Buffer/Reader (A12)
* Function list: (...).
*************************************************************/

/*
 *.............................................................................
 * ADVICE 1:
 * Please check the "TODO" labels to develop your activity.
 *
 * ADVICE 2: Preprocessor directives
 * The #define _CRT_SECURE_NO_WARNINGS should be used in MS Visual Studio projects
 * to suppress the warnings about using "unsafe" functions like fopen()
 * and standard sting library functions defined in string.h.
 * The define directive does not have any effect on other compiler projects 
 * (Gcc, VSCode, Codeblocks, etc.).
 *.............................................................................
 */

#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

#ifndef COMPILERS_H_
#include "Compilers.h"
#endif

#ifndef CODER_H_
#include "Step1Coder.h"
#endif

 /* Check for ANSI C compliancy */
#define ANSI_C 0
#if defined(__STDC__)
#undef ANSI_C
#define ANSI_C 1
#endif

/*
 * TODO .......................................................................
 * Basically, change all datatypes to your language definitions
 * (see "Compilers.h")
 */

/*
 * -------------------------------------------------------------
 *  Function declarations
 * -------------------------------------------------------------
 */

/*
************************************************************
* Coder starting method
* Params:
*	- Mode: Cypher/decypher
*	- Input: Filename
*   - Key: Encrypt word
*	- Output: Filename
************************************************************
*/

// Main function to handle command-line arguments
keets_intg main1Coder(keets_intg argc, keets_strg* argv) {
	if (argc < 5) {
		printf("Usage: %s [cypher=1|decypher=0] <input_file> <output_file>\n", argv[0]);
		return EXIT_FAILURE;
	}
	keets_strg operation = "";
	keets_strg inputFileName = "";
	keets_strg key = STR_LANGNAME;
	keets_strg outputFileName = "";
	if (argc > 4) {
		operation = argv[2];
		inputFileName = argv[3];
		outputFileName = argv[4];
		// Call the appropriate function to file
		if (atoi(operation) == CYPHER)
			cypher(inputFileName, outputFileName, key);
		else if (atoi(operation) == DECYPHER)
			decypher(inputFileName, outputFileName, key);
		else {
			errorPrint("%s%s%s", "Error: Unknown operation ", operation, ". Use 'cypher' or 'decypher'.\n");
			return EXIT_FAILURE;
		}
		printf("Operation '%s' completed successfully.\n", operation);
		// Call the other operation in memory
		keets_intg size = getSizeOfFile(outputFileName);
		keets_strg output;
		if (atoi(operation) == CYPHER)
			output = vigenereMem(outputFileName, key, DECYPHER);
		else 
			output = vigenereMem(outputFileName, key, CYPHER);
		printf("OUTPUT:\n%s\n", output);
	}
	return EXIT_SUCCESS;
}



