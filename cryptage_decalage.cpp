#include <iterator>
#include <algorithm>
#include <iostream>
#include <string>
#include <functional>
#include <cctype>
using namespace std;


int decalage(){
cout<<"enterer le decalage du cryptage"<<endl;
int dec;
cin>>dec;
return  (dec%26 ) ;}


class cryptage{
public:
cryptage(int n):decalage(n){}
char operator() (char c) {
if (isupper(c))
return(c+decalage);
return c;
}
private:
int decalage ;



};

int main(){
string s="ABDtrrttrtr";
int dec=decalage();
cryptage crypte(dec);
transform(s.begin(),s.end(),s.begin(),crypte);
ostream_iterator<char> it1(cout,".");
for(string::iterator it=s.begin();it!=s.end();it++)
*it1=*it;
cout<<endl;


return 0;}




