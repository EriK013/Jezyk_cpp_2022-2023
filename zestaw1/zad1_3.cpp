#include <iostream>
#include <string>

using namespace std;
string format(string s);
string odwroc(string s);
string polskie1(char a);
string polskie2(char a);

int main(){
    string input;
    getline(cin, input);
    string zdanie = format(input);
    string zdanie_odwrocone = odwroc(zdanie);
    if(zdanie_odwrocone == zdanie){
        cout << "Zdanie jest palindromem" << endl;
        return 0;
    }
    else{
        cout << "Zdanie nie jest palindromem" << endl;
        return 0;
    }
    return 1;
}


//Funkcja przepisująca zdanie. Usuwa białe znaki i zmienia wielkość każdej z litery na małą
string format(string s){
    string tmp;
    int i=0;
    while(i<s.length()){
        char c = s[i];
        if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'){
            tmp += tolower(c);
        }
        else{
            c = s[i + 1];
            tmp += polskie2(c);
        }
        i ++;
    }
    return tmp;
}
//funkcja odwracająca zdanie
string odwroc(string s){
    string tmp;
    char a;
    int i=s.length() - 1;
    while(i >= 0){
        a = s[i];
        if ( a >= 'A' && a <= 'Z' || a >= 'a' && a <= 'z' ){
            tmp += a;
            i--;
        }
        else{
            tmp += polskie1(a);
            i -= 2;
        } 
    }
    return tmp;
}

//Rozwiązanie problemu polskich znaków (przy czytaniu od ostatniego znaku program w nieprawidłowy sposób przepisywał polskie znaki)
string polskie1(char a){
    string znak;
    if (a == -68){
        znak += "ż";
    }
    else if(a == -70){
        znak += "ź";
    }
    else if(a == -101){
        znak += "ś";
    }
    else if(a == -77){
        znak += "ó";
    }
    else if(a == -124){
        znak += "ń";
    }
    else if(a == -126){
        znak += "ł";
    }
    else if(a == -103){
        znak += "ę";
    }
    else if(a == -121){
        znak += "ć";
    }
    else if(a == -123 || a == -60){
        znak += "ą";
    }
    return znak;
}

string polskie2(char a){
    string znak;
    if (a == -68){
        znak += "ż";
    }
    else if(a == -71){
        znak += "ź";
    }
    else if(a == -102){
        znak += "ś";
    }
    else if(a == -109){
        znak += "ó";
    }
    else if(a == -125){
        znak += "ń";
    }
    else if(a == -127){
        znak += "ł";
    }
    else if(a == -104){
        znak += "ę";
    }
    else if(a == -122){
        znak += "ć";
    }
    else if(a == -124){
        znak += "ą";
    }
    return znak;
}
