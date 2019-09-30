using System;
class A{
static void Main()
{
string a=Console.ReadLine();
//string n="";
bool flag=true;
for(int i=0;i<a.Length/2;i++){
string n=a.Substring(a.Length-1-i,1);
string s=a.Substring(i,1);
if(n==s||n=="*"||s=="*"){}else{flag=false;}
}Console.WriteLine(flag?"YES":"NO");

}
}