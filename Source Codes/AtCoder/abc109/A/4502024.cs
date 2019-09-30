using System;
using System.Linq;

class Program
{
    public static void Main(string[] args) {
        int[] s = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int ab = s[0]*s[1];
        for (int i = 1; i <= 3; i ++) {
            if (ab*i%2 == 1) {
                Console.WriteLine("Yes");
                return;
            }
        }
        Console.WriteLine("No");
    }
}