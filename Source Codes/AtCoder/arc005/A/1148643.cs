using System;
class A{
static void Main(){int s=int.Parse(Console.ReadLine());
string []a=Console.ReadLine().Split();
int ans=0;
for(int i=0;i<s;i++){
if(a[i]=="TAKAHASHIKUN"||  a[i]== "takahashikun"||a[i]=="Takahashikun"||a[i]=="TAKAHASHIKUN."||  a[i]== "takahashikun."||a[i]=="Takahashikun."){ans++;}
}
Console.WriteLine(ans);
}
}