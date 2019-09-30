using System;

class Program{
  static void Main(string[] args){
    
    int i;
    string[] c = new string[3];
    for(i = 0; i < 3; i++){
        c[i] = Console.ReadLine();
    }
    
    for(i = 0; i < 3; i++){
      Console.Write(c[i][i]);
    }
  }
}