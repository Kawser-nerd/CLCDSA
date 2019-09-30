using System;
using System.Linq;
class Program
{
    private char[] Reverse(char[] str, int s, int g)
    {
        char[] str2 = new char[str.Length];
        for (int i = 0; i < str.Length; i++)
            str2[i] = str[i];
        for (int i = 0; i < (g - s + 1) / 2; i++)
        {
            str2[g - 1 - i] = str[s - 1 + i];
            str2[s - 1 + i] = str[g - 1 - i];
        }
        return str2;
    }
    public static void Main()
    {
        string str = Console.ReadLine();
        char[] s = new char[str.Length];
        for (int i = 0; i < str.Length; i++)
            s[i] = str[i];
        int n = int.Parse(Console.ReadLine());
        Program prog = new Program();
        int st = 0, go = 0;
        string[] import;
        for (int i = 0; i < n; i++)
        {
            import = Console.ReadLine().Split(' ');
            st = int.Parse(import[0]);
            go = int.Parse(import[1]);
            s = prog.Reverse(s, st, go);
        }
        for (int i = 0; i < s.Length; i++)
            Console.Write(s[i]);
        Console.WriteLine();
    }
}