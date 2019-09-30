using System;
class main{
  public static void Main(){
  	string[] input = Console.ReadLine().Split(' ');
    int A = int.Parse(input[0]);
    int B = int.Parse(input[1]);
    if(B/A < 1){
   		Console.WriteLine(0);
    }else{
		Console.WriteLine(B/A);
    }
  }
}