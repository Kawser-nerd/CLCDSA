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
        var ans = a - b == 0? c : a - c == 0? b : a;
        //??
        Console.WriteLine(ans.ToString());
      }
    }