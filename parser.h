#ifndef PARSER_H
#define PARSER_H
#include <iostream>     // cin & cout
#include <string>       // Strings are better then char arrays
#include <cstring>      // size_t
#include <fstream>      // File usage
#include "token.h"
#include "node.h"
#include "scanner.h"
using namespace std;

class Parser: public Scanner{
    private:
        // File Information
        ifstream file;      // File the parse will input information into
        string inputInfo;   // Information being put into file

        Token tk;           // Holds token
        Token EmpTK;      // Empty token
        string predictTK;  // Predicts tokens in the event of an error

        Scanner scanner;    // Scanner obj
        int scannerStatus;   // Status code of scanner, used to know if using new line or old line

        // BNF of Program
        Node *program();
        Node *block();
        Node *vars();
        Node *expr();
        Node *N();
        Node *A();
        Node *R();
        Node *stats();
        Node *mStat();
        Node *stat();
        Node *in();
        Node *out();
        Node *iff();
        Node *loop();
        Node *assign();
        Node *RO();

        void nextScan();
        Node *newNode(string prodoName);
        void parserError();
    
    public:
        Parser(string fileName);
        Node *parse();

};

#endif