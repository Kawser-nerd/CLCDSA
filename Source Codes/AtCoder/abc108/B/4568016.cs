using System;
using System.Linq;

class Program
{
    static void Main(string[] args) {
        int[] s = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int x3 = s[2]-s[3]+s[1];
        int y3 = s[3]+s[2]-s[0];
        int x4 = x3-y3+s[3];
        int y4 = y3+x3-s[2];
        Console.WriteLine("{0} {1} {2} {3}", x3, y3, x4, y4);
    }
}