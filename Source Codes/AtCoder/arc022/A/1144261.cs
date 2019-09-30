using System;//.Linq;
class A{
static void Main()
{
string a=Console.ReadLine();
int s=0;
for(int i=0;i<a.Length;i++){
string d=a.Substring(i,1);
if(s==0&&(d=="I"||d=="i")){s=1;}
if(s==1&&(d=="C"||d=="c")){s=2;}
if(s==2&&(d=="T"||d=="t")){s=3;}
}
if(s==3){Console.WriteLine("YES");}
else {Console.WriteLine("NO");}
}
}