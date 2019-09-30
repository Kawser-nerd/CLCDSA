using System;

class Program{
	static void Main(string[] args){
    	int N = int.Parse(Console.ReadLine());
      	int K = int.Parse(Console.ReadLine());
      	int X = int.Parse(Console.ReadLine());
       	int Y = int.Parse(Console.ReadLine());
      
      	if(N>= K)
        {
          Console.WriteLine((K * X) + ((N - K) * Y));
        }else{
        	Console.WriteLine(N * X);
        }
    }
}