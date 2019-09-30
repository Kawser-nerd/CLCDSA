using System;
using static System.Console;
using System.Linq;
class B{
  static void Main(){
    ReadLine();
    var ts = Array.ConvertAll(ReadLine().Split(), int.Parse);
    var sum = ts.Sum();
    var n = int.Parse(ReadLine());
    for(int i = 0;i < n; i++){
      var px = Array.ConvertAll(ReadLine().Split(), int.Parse);
      WriteLine(sum-ts[px[0]-1]+px[1]);
    }
  }
}