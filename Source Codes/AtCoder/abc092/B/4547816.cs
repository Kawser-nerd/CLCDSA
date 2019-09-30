using System;
using System.Linq;

class Program
{
    static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        int[] s = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int d = s[0];
        int x = s[1];
        for (int i = 0; i < n; i++) {
            int a = int.Parse(Console.ReadLine());
            for (int j = 0; j*a+1 <= d; j ++) {
                x ++;
            }
        }
        Console.WriteLine(x);
    }
}