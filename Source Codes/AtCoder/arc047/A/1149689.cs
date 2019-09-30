using System;//.Linq;
using System.Linq;
class A{
static void Main()
{int tab=1;
int ans=0;
int []a=Console.ReadLine().Split().Select(int.Parse).ToArray();
string s=Console.ReadLine();string g="";
for(int i=0;i<a[0];i++)
{
g=s.Substring(i,1);
if(g=="+"){tab++;}
else{tab--;}
if(tab>a[1]){ans++;tab-=1;tab=1;}
//Console.WriteLine(tab);
}Console.WriteLine(ans);
}
}