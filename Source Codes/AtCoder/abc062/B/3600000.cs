using System;
using System.Linq;

class prog{
  static void Main(){
    
    int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
    string[] pic = new string[input[0] + 2];
    for(int i = 1; i <= input[0]; i++){
      pic[i] = "#" + Console.ReadLine() + "#";
    }
    
    for(int i = 0; i < input[1] + 2; i++){
      pic[0] += "#";
      pic[input[0] + 1] += "#";
    }
    
    for(int i = 0; i < input[0] + 2; i++){
      Console.WriteLine(pic[i]);
    }
  }
}