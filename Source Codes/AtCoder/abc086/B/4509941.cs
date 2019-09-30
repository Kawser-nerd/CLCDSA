using System;
using System.Linq;

class Program
{
    public static void Main(string[] args) {
        string[] s = Console.ReadLine().Split().ToArray();
        int ab = int.Parse(s[0]+s[1]);
        Console.WriteLine(judge(ab) ? "Yes" : "No");
    }
    public static bool judge(int a) {
        for (int i = 1; Math.Pow(i,2) <= a; i ++) {
            if (a/i == i && a%i == 0) return true;
        }
        return false;
    }
}