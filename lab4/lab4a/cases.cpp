using namespace std;

#include <iostream>
#include <cctype>

void lower(string &s){
    char c;
    for (unsigned int i = 0; i < s.length(); i++){
        c = s[i];
        c = tolower(c);
        s.replace(i, 1, 1, c);
    }
}

void upper(string &s){
    char c;
    for (unsigned int i = 0; i < s.length(); i++){
        c = s[i];
        c = toupper(c);
        s.replace(i, 1, 1, c);
    }
}

string capitalise(const string &s){
    string output(s);
    unsigned int startPos, endPos = 0;
    char c;
    std::size_t found = s.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", endPos);
    while (found != string::npos){
        startPos = found;
        endPos = startPos + 1;
        c = s[startPos];
        c = toupper(c);
        output[startPos] = c;
        while (s[endPos] != ' '){
            c = s[endPos];
            c = tolower(c);
            output[endPos] = c;
            endPos++;
        }
        found = s.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", endPos);
    }
    return output;
}

int main() {
    string s1 = "Who? What? Where? When? Why?";
    string s2 = "cStRiNgS aRe BeTtEr ThAn StRiNg ObJeCtS";
    lower(s1);
    lower(s2);
    cout << s1 << endl << s2 << endl;
    upper(s1);
    upper(s2);
    cout << s1 << endl << s2 << endl;

    cout << capitalise("#i do not use capitals") << endl
     << capitalise("i uSE cAPITALS wRONG") << endl
     << capitalise("i -sd weird-@*#cases $(&$£)sa") << endl;

}
