using System;
using System.Linq;
public class P{
public static void Main(){
long a=1,b=0,N=long.Parse(Console.ReadLine());
long? dist=0,doko=0,temp,d=0;
for(int i=2;i<=N;i++){
Console.WriteLine("? {0} {1}", 1, i);
if((temp = long.Parse(Console.ReadLine()))>=dist){
doko=i;
dist=temp;
}
}
for (int i=1;i<=N;i++){
Console.WriteLine("? {0} {1}", doko, i);
if((temp = long.Parse(Console.ReadLine()))>=dist){
dist=temp;
d=i;
}
}
Console.WriteLine("! {0}",dist);
}
}