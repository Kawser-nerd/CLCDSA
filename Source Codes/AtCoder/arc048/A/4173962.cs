using System;
using System.Linq;

class P{
  static void Main(){
    var input = Console.ReadLine().Split().Select(long.Parse).ToArray();
    if(input[0]*input[1]>0) Console.WriteLine(input[1]-input[0]);
    else Console.WriteLine(input[1]-input[0]-1);
  }
}