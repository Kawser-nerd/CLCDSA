using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;

// using System.Text;
public class Program
{
    public static void Main(string[] args)
    {
        // ????(??)
        var input = Console.ReadLine().Split(' ');
        // ?
        var width = BigInteger.Parse(input[0]);
        // ??
        var height = BigInteger.Parse(input[1]);
        // ???
        var depth = BigInteger.Parse(input[2]);
        // ??
        var volume = width * height * depth;

        // 10^9+7??????
        var remainder = volume % (BigInteger)(Math.Pow(10, 9) + 7);
        Console.WriteLine(remainder);
        Console.ReadLine();
    }
}