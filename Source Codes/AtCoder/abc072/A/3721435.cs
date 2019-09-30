using System;
    class Program
    {
      static void Main(string[] args)
      {
        // ?????????????
        string[] input = Console.ReadLine().Split(' ');
        var a = int.Parse(input[0]);
        var b = int.Parse(input[1]);
        var ans = ((a - b) > 0)? a - b : 0;
        //??
        Console.WriteLine(ans);
      }
    }