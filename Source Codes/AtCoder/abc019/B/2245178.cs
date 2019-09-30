using System;
using System.Linq;

class Program {
    static void Main(string[] args) {
        var s = Console.ReadLine();
        string t = null;
        int i = 0;
        while (i < s.Length) {
            int start = i;
            while (i < s.Length && s[start] == s[i]) i++;
            t += s[start] + (i - start).ToString();
        }
        Console.WriteLine(t);
    }
}