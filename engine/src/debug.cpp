#include "debug.h"
#include <nds.h>
#include <stdio.h>

void Debug::Print(std::string str) {
    iprintf("\x1b[1;1H%s\n", str.c_str()); 
}

void Debug::Clear() {
    iprintf("\x1b[2J");
}