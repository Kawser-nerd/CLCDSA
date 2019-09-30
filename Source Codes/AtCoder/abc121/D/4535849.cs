using System;
using System.Linq;

class Program
{
    static void Main(string[] args) {
        long[] s = Console.ReadLine().Split().Select(long.Parse).ToArray();
        long a = s[0];
        long b = s[1];
        Console.WriteLine(f(b)^f(a-1));
    }
    static long f(long x) {
        switch (x%4) {
            case 0: return x;
            case 1: return 1;
            case 2: return x+1;
            default: return 0;
        }
    }
}