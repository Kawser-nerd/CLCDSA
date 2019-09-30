using System;
using System.Linq;
class Program
{
    public static void Main()
    {
        char[] choku = { 'c', 'h', 'o', 'k', 'u' };
        string x = Console.ReadLine();
        bool f = true;
        for (int i = 0; i < x.Length; i++)
            f = f && choku.Contains(x[i]);
        if (!f)
            Console.WriteLine("NO");
        else
        {
            if (x[x.Length - 1] == 'c'|| x[0] == 'h')
                f = false;
            else if (x.Length > 1)
            {
                for (int i = 0; i < x.Length - 1; i++)
                {
                    if (x[i] == 'c' && x[i + 1] != 'h')
                        f = false;
                }
                for (int i = 1; i < x.Length; i++)
                {
                    if (x[i] == 'h' && x[i - 1] != 'c')
                        f = false;
                }
            }
            Console.WriteLine(f ? "YES" : "NO");
        }
    }
}