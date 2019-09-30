using System;

class Program
{
    static void Main(string[] args) {
        string s = Console.ReadLine();
        int ans = 0;
        for(int i = 0; i < s.Length; i ++) {
            if(s[i] == '+') ans ++;
            else ans --;
        }
        Console.WriteLine(ans);
    }
}