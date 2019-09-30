using System.Linq;
using System;
class A{
static void Main()
{int ans=0;
long []d=Console.ReadLine().Split().Select(long.Parse).ToArray();
long a=d[0],k=d[1];
long shoji=d[0];if(d[1]==0){Console.WriteLine(2000000000000-d[0]);}
else{while(true){
if(shoji>=2000000000000){
break;
}ans++;
shoji+=1+shoji*k;
}Console.WriteLine(ans);
}}
}