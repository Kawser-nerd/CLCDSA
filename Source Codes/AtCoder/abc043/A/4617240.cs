using System;

class Program{
	static void Main(string[] args){
    	int N = int.Parse(Console.ReadLine());
      	int count = 0;
      	for(int i = 0;i < N;i ++){
        	count += i + 1;
        }
      Console.WriteLine(count);
    }
}