using System;
using System.Linq;

class Program
{
    static void Main(string[] args) {
        int[] s = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int n = 0;
        for(int i = 1; i <= s[1]-s[0]; i ++) {
            n += i;
        }
        Console.WriteLine(n-s[1]);
    }
}