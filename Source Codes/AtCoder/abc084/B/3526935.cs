using System;
using System.Linq;

class prog{
  
  static bool judge(string input){
    bool judge = true;
    foreach(char i in input){
      if(i == '-') judge = false;
    }
    return judge;
  }
  
  static void Main(){
    int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
    string S = Console.ReadLine();
    int A = input[0];
    int B = input[1];
    
    if(judge(S.Substring(0,A))&&S.Substring(A,1) == "-"&&judge(S.Substring(A+1))) Console.WriteLine("Yes");
    else Console.WriteLine("No");
  }
}