using System;

class Program{
  
  static void Main(string[] args){
    
    string[] str = Console.ReadLine().Split(' ');
    
    int X = int.Parse(str[0]);
    int Y = int.Parse(str[1]);
    
    if(X > Y){
      Console.WriteLine(X);
    }else{
      Console.WriteLine(Y);
    }
  }
}