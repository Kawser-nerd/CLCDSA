using System;
using System.Linq;

class Program
{
    static void Main(string[] args) {
        char[] s = Console.ReadLine().ToCharArray();
        char[] t = Console.ReadLine().ToCharArray();
        int n = s.Length;
        int m = t.Length;
        Array.Sort(s);
        Array.Sort(t);
        Console.WriteLine(solve1(s, t, n, m) || solve2(s, t, n, m) ? "Yes" : "No");
    }
    static bool solve1(char[] s, char[] t, int n, int m) {
        if(n < m) {
            for(int i = 0; i < n; i ++) {
                if(Array.IndexOf(t, s[i]) < 0) return false;
            }
            return true;
        }
        else return false;
    }
    static bool solve2(char[] s, char[] t, int n, int m) {
        Array.Reverse(t);
        for(int i = 0; i < Math.Min(n,m); i ++) if(s[i] < t[i]) return true;
        return false;
    }
}