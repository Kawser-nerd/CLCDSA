using System;
using System.Linq;
 
class Program
{
    static void Main(string[] args) {
        int[] s = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int x = Console.ReadLine().Split().Select(int.Parse).ToArray().Max();
        int y = Console.ReadLine().Split().Select(int.Parse).ToArray().Min();
        Console.WriteLine(solve(x, y, s[2], s[3]) ? "No War" : "War");
    }
    static bool solve(int x, int y, int X, int Y) {
        for (int i = -100; i <= 100; i ++) {
            if (i > X && i <= Y && i > x && i <= y) return true;
        }
        return false;
    }
}