using System;
using System.Linq;
class P{
  static int Euc(int a,int b){
    if(a<b)return Euc(b,a);
    else if(a%b==0)return b;
    else return Euc(b,a%b);
  }
  static void Main(){
    int N=int.Parse(Console.ReadLine());
    var s=Console.ReadLine().Split().Select(int.Parse).ToArray();
    int ans=s[0];
    foreach(int x in s)ans=Euc(ans,x);
    Console.WriteLine(ans);
  }
}