using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {
        var array = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
        long A = array[0];
        long B = array[1];
        long C = array[2];
        long K = array[3];
        if (Math.Abs(A - B) > Math.Pow(10, 18)) Console.WriteLine("Unfair");
        var res = K % 2 == 0 ? A - B : B - A;
        Console.WriteLine(res);
    }
}