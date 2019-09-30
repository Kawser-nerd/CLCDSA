using System;
using System.Linq;

class Program
{
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        string[] w = new string[n];
        w[0] = Console.ReadLine();
        for (int i = 1; i < n; i ++) {
            w[i] = Console.ReadLine();
            if (w.Where(x => x == w[i]).Count() != 1 || w[i-1].Substring(w[i-1].Length-1,1) != w[i].Substring(0,1)) {
                Console.WriteLine("No");
                return;
            }
        }
        Console.WriteLine("Yes");
    }
}