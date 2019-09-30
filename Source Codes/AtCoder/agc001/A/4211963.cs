using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program {
    static void Main(string[] args) {
        //??
        int N = int.Parse(Console.ReadLine());
        string s = Console.ReadLine();

        int[] L = new int[2 * N];

        for (int i = 0; i < 2 * N; i++) {
            L[i] = int.Parse(s.Split(' ')[i]);
        }

        //????
        Array.Sort(L);

        //?????
        int ans = 0;

        //??
        for (int i = 0; i < 2 * N; i = i + 2) {
            ans += Math.Min(L[i], L[i + 1]);
        }

        //??
        Console.WriteLine(ans);
    }
}