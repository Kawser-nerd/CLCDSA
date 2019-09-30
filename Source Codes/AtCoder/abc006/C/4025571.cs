using System;
using System.Linq;
class P{
  static void Main(){
    var a=Console.ReadLine().Split().Select(int.Parse).ToArray();
    if(a[0]*2>a[1]|a[0]*4<a[1]){
      Console.WriteLine("-1 -1 -1");
      return;
    }
    int y=a[1]%2;
    a[1]-=3*y;
    a[0]-=y;
    Console.WriteLine($"{2*a[0]-a[1]/2} {y} {a[1]/2-a[0]}");
  }
}