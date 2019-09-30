using System;
    class Program
    {
      static void Main(string[] args)
      {
        // ?????????????
        string[] input = Console.ReadLine().Split(' ');
        var a = int.Parse(input[0]);
        var b = int.Parse(input[1]);
        var c = int.Parse(input[2]);
        var d = int.Parse(input[3]);
        var lib = (a + b) - (c + d);
        var ans = lib == 0? "Balanced" : lib > 0? "Left": "Right";
        //??
        Console.WriteLine(ans);
      }
    }