#include<iostream>
#include<string>
#include <algorithm>
#include <map>
#include <iterator>
#include <fstream>
using namespace std;

class lecture{ 
public:
lecture(string fichier)
 {
file=ifstream(fichier);
}

map <char,char> affectation()

{
map<char,char> tab;
istream_iterator<char> it(file);
istream_iterator<char> fin;
while (it != fin){
char c1=*it;
++it;
char c2=*it;
++it;
tab[c1]=c2;
}
return tab;
}
private :
ifstream file;};


class cryptage{

public :
cryptage(){

lecture sub("cle.txt");
tab=sub.affectation();}



char operator()( char c){
if (tab.find(c)!=tab.end())
return (tab[c]);
return c;}
 private:
map<char,char> tab;};








int main(){
string s="etAzOzDezIzKOIk4O";
cout<<s<<endl;
cryptage c;
transform(s.begin(),s.end(),s.begin(),c);
cout<<endl<<s<<endl;
return 0;}
