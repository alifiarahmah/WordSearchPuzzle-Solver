#include <iostream>
#include <string>
using namespace std;

/// https://stackoverflow.com/questions/9158150/colored-output-in-c
#define RESET   "0"
#define BLACK   "30"      /* Black */
#define RED     "31"      /* Red */
#define GREEN   "32"      /* Green */
#define YELLOW  "33"      /* Yellow */
#define BLUE    "34"      /* Blue */
#define MAGENTA "35"      /* Magenta */
#define CYAN    "36"      /* Cyan */
#define WHITE   "37"      /* White */

void print_color(string s, short int x){
	cout << "\033[" << x << "m" << s << "\033[0m";
}