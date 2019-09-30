using System;

class Program
{
    static void Main(string[] args) {
        string s = Console.ReadLine();
        string t = Console.ReadLine();
        Console.WriteLine(solve(s,t) ? "Yes": "No");
    }
    static bool solve(string s, string t) {
        int l = s.Length;
        for(int i = 0; i < l; i ++) {
            if(s == t) return true;
            s = s[l-1].ToString() + s.Substring(0, l-1);
        }
        return false;
    }
}