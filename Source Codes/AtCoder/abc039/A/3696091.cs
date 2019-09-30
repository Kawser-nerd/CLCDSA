using System;

class Program
{
    static void Main()
    {
        var data = Console.ReadLine().Split();
        var a = int.Parse(data[0]);
        var b = int.Parse(data[1]);
      	var c = int.Parse(data[2]);
      	
      	Console.WriteLine(2 * (a * b + b * c + c * a));
    }
}