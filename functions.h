#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <sstream>
#include <bitset>
#include <string.h> 

using namespace std;
int checkIPAddress(string, int);
string convertMaskDecToBin(int);
string convertDecToBin(const int [], string []);
void convertDecOctetToBinOctet(const int [], string []);
string calculateNetworkAddress(string, string);
void calculateNetworkClass(int);
string doBitwiseNOT(string);
string calculateBroadcastAddress(string, string);
void splitString(string, vector<string>&);
void convertStringOctetToIntOctet(int[], vector<string>);
void calculateFirstHostAddress(int[], int[]);
void calculateLastHostAddress(int[], int[]);
int calculateMaxHostNumber(int);
void printToTheScreen(int[]);
void printToTheScreen(vector<string>);
void printToTheScreen(string[]);

#endif _FUNCTIONS_H_