using System;
using System.Linq;

class Program
{
    static void Main(string[] args) {
        int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
        string s = Console.ReadLine();
        int i = 0;
        Console.WriteLine(s.Substring(n[0],1) == "-" && int.TryParse(s.Substring(0, n[0]), out i) && int.TryParse(s.Substring(n[0]+1), out i) ? "Yes" : "No");
    }
}