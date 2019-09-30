using System;

class MainClass{
	public static void Main(){
    	var tmp = Console.ReadLine().Split(' ');
    	int a = int.Parse(tmp[0]), b = int.Parse(tmp[1]), c = int.Parse(tmp[2]);
      	Console.WriteLine((a * c < b) ? c : b / a);
    }
}