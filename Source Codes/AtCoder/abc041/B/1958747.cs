using System;
using System.Linq;
using System.Collections.Generic;

public class Hello
{
    public static void Main()
    {
        ulong[] n = Console.ReadLine().Split(' ').Select(i => ulong.Parse(i)).ToArray();
        ulong a = n[0] % 1000000007;
        ulong b = n[1] % 1000000007;
        ulong c = n[2] % 1000000007;
        Console.WriteLine((((a*b)%1000000007)*c)%1000000007);
    }
}