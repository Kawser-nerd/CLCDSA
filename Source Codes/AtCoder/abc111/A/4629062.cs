using System;
using System.Linq;

class Program
{
    static void Main(string[] args) {
        char[] chr = Console.ReadLine().ToCharArray();
        Console.WriteLine(solve(chr));
    }
    static string solve(char[] c){
        for (int i = 0; i<c.Length; i ++) {
            c[i] = c[i]== '1' ? '9':'1';
        }
        string s = new String(c);
        return s;
    }
}