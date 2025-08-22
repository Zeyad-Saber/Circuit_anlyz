#include <iostream>
#include <vector>
#include <string>
#include <cctype> // for isdigit

using namespace std;
bool isvalidChar(char c) {
    // Check if the character is a digit or one of the suitable letters (s, e, p)
    return isdigit(c) || c == 'S' || c == 'P' || c == '.'||
           c == 's' || c == 'e' || c == 'p' || c == ' ' || c == ',';
}

void check_string(const string& input) {
    for (char c : input) {
        if (!isvalidChar(c)) {
            cout << "Wrong Description" << endl;
            return; // Stop processing if an invalid character is found
        }
}}

 // series function
double Sconnection (const vector<double>& r_s) {
    double totalResistance = 0;
    for (int i = 0 ; i<r_s.size() ; i++ ) {
        totalResistance += r_s[i];
    }
    return totalResistance;
}


// parallel function
double Pconnection(const vector<double>& r_s) {
    double totalReciprocal = 0;
    for (int i = 0 ; i<r_s.size() ; i++  ) {
        totalReciprocal += 1 / r_s[i];
    }
    return 1 / totalReciprocal;
}

// calculating Req
double rcalc(string input ){
string current = "";
 vector<double> r_s;

char type = input[0];
for (int i = 2; i < input.length(); ++i) {
        if (input[i] == ' ' || input[i] == ',' ) {
            if (!current.empty() && current != "e") {
                r_s.push_back(stod(current));}

            current = "";}
            else {current += input[i];}
    }

    if (!current.empty() && current != "e") {
        r_s.push_back(stod(current));}

    double totalResistance = 0;

    if (type == 'S' || type == 's') {
        totalResistance = Sconnection(r_s);}
    else if (type == 'P' || type == 'p') {
        totalResistance = Pconnection(r_s);}

return totalResistance ;}

// ------------------ Main FN

int main() {

    string input;
    getline(cin, input);
    vector<double> r_s;
    string current = "";
    string sx = "" ;
check_string(input);
    double totalcResistance = 0;
     double totalResistance = 0;
// finding first 'e,p,s' to detect start and end of connections
      int e = input.find_first_of ('e')  ;
    int p ;
   int s ;

  while(e != input.size()-1 ){ //if still there is child connections
    p = input.find_last_of ('p',e);
    s = input.find_last_of ('s',e);
    int z = p>s ? p:s ; // z is a variable used for both s and p and choose the smaller connection
string child = input.substr(z,e-z+1); // substring child connection
 totalcResistance = rcalc(child); // Req of child connection

sx = to_string(rcalc(child)); // Convert Req of child coonection to a string
input = input.replace(z,e-z+1,sx); // replace the child connection with its Req
e = input.find_first_of ('e')  ;  //Finds if still there is other child connection or not

    }


 if (e == input.size()-1){               //if there is no child connections

totalResistance = rcalc(input);    // calculate Req directly
 cout << "The total resistance = " << totalResistance << endl;}


    return 0;
}
