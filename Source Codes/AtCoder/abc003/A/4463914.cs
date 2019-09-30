using System;

class Program{
  
  static void Main(string[] args){
    
    int N = int.Parse(Console.ReadLine());
    
   
    int Total = 0;
    
    for(int i = 1; i <= N; ++i){
     
      Total += i * 10000;
  }
    int ave = Total / N;
     Console.Write(ave);
 }
}