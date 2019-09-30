using System;
using System.Linq;

class prog{
  static void Main(){
    int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
    var l = Console.ReadLine().Split().Select(int.Parse).OrderByDescending(x => x).ToArray();
    int ans = 0;
    for(int i = 0; i < input[1]; i++){
      ans += l[i];
    }
    Console.WriteLine(ans);
  }
}