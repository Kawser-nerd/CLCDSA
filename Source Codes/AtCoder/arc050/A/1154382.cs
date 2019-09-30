using System;//using System.Linq;
class A{
static void Main()
{
string []a=Console.ReadLine().Split();
bool f=false;
if(a[1].ToUpper()==a[0]){f=true;}Console.WriteLine(f?"Yes":"No");
}
}