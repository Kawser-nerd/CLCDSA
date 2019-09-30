using System;
using System.Linq;

class prog{
  static void Main(){
    int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
    
    int ans;
    if (input[1] < input[2]||input[0] > input[3]) ans = 0;
    else if ((input[0] <= input[2]&&input[1] >= input[3])||(input[0] >= input[2]&&input[1] <=input[3])) ans = Math.Min(input[1] - input[0], input[3] - input[2]);
    else ans = Math.Min(input[1] - input[2], input[3] - input[0]);
    
    Console.WriteLine(ans);
    
  }
}