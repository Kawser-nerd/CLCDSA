using System;
using System.Linq;

class prog{
  static void Main(){
    string[] input = Console.ReadLine().Split();
    string ans = "" + (char)(input[0][0] - 'a' + 'A') + (char)(input[1][0] - 'a' + 'A') + (char)(input[2][0] - 'a' + 'A');
    Console.WriteLine(ans);
  }
}