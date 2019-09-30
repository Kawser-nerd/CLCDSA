using System;
using System.Linq;

class Program
{
    static void Main(string[] args) {
        int[][] c = new int[3][];
        c[0] = Console.ReadLine().Split().Select(int.Parse).ToArray();
        c[1] = Console.ReadLine().Split().Select(int.Parse).ToArray();
        c[2] = Console.ReadLine().Split().Select(int.Parse).ToArray();
        Console.WriteLine(solve(c) ? "Yes" : "No");
    }
    static bool solve(int[][] c) {
        for (int i = 0; i < c.Length; i ++) {
            int min = c[i].Min();
            for (int j = 0; j < c[i].Length; j ++) {
                c[i][j] -= min;
            }
        }
        for (int i = 0; i < c.Length; i ++) {
            if(c[0][i] != c[1][i] || c[1][i] != c[2][i]) return false;
        }
        return true;
    }
}