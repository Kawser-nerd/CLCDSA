using System;

class Program
{
    static void Main(string[] args) {
        string s = Console.ReadLine();
        Console.WriteLine(solve1(s) == true && solve2(s) == true && solve3(s) == true ? "AC" : "WA");
    }
    static bool solve1(string s) {
        return s[0]=='A';
    }
    static bool solve2(string s) {
        for (int i = 2; i < s.Length-1; i ++) {
            if (s[i]=='C') return true;
        }
        return false;
    }
    static bool solve3(string s) {
        int count = 0;
        for (int i = 0; i < s.Length; i ++) {
            if(char.IsUpper(s[i])) count ++;
        }
        return count == 2;
    }
}