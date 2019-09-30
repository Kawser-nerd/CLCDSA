using System;
using System.Linq;

class Program
{
    static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        int count = 0;
        for (int i = 5; i <= n; i += 2) {
            int d = 2;
            for (int j = 3; j < i; j += 2) {
                if (i%j == 0) d ++;
                if (j == i-2 && d == 8) count ++;
            }
        }
        Console.WriteLine(count);
    }
}