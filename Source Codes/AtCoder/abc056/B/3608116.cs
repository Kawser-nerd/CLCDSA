using System;
using System.Linq;

class prog{
  static void Main(){
    int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int w = input[0];
    int a = input[1];
    int b = input[2];
    int ans = 0;
    if(a > b + w||b > a + w) ans = Math.Abs(a - b) - w;
    Console.WriteLine(ans);
  }
}