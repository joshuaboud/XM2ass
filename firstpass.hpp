/* File name: firstpass.hpp
 * Author: Josh Boudreau
 * School: Dalhousie University
 * Course: ECED 3403 - Computer Architecture
 * Purpose: Necessary includes and declarations for firstpass.cpp.
 * 			Inlude this file to call the first pass state machine or
 * 			change the state variable.
 * Last Modified: 2019-05-30
 */

#ifndef FIRSTPASS_H
#define FIRSTPASS_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

#include "commands.hpp"
#include "symbols.hpp"
#include "record.hpp"

enum FPState { CHECK_FIRST_TOKEN, CHECK_INST_DIR, CHECK_DIR, \
	CHECK_INST };	//	state machine control for first pass

extern unsigned int START; // starting memory location for loader
// defined in main as 0, modified by END directive

void firstPassStateMachine(ifstream & source);
// enter state machine

void checkFirstToken(istringstream & record, string & token, int & tblSub);
// reads first token of record, decide state change

void checkInstOrDir(istringstream & record, string & token, int & tblSub);
// Retrieves table index of inst or dir, changes state to process inst
// or dir. If not found, push error and return.

void checkInst(istringstream & record, string & token, int & tblSub, uint16_t & memLoc);
// Verifies operands of instruction and adds to list of records with location counter.

void checkDir(istringstream & record, string & token, int & tblSub, uint16_t & memLoc, string label);
// Verifies operands of directive and adds to list of records, modifies location counter
// for applicable directives.

#endif
