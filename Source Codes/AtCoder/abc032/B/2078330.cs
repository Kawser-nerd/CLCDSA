using System;
using System.Linq;
class Program
{
    public static void Main()
    {
        string s = Console.ReadLine();
        int k = int.Parse(Console.ReadLine());
        int n = Math.Max(0, s.Length - k + 1);
        if (n == 0)
            Console.WriteLine(0);
        else
        {
            string[] pass = new string[n];
            string p = "";
            for (int i = 0; i < n; i++)
            {
                for (int j = i; j < i + k; j++)
                    p += s[j];
                pass[i] = p;
                p = "";
            }
            Console.WriteLine(pass.Distinct().ToArray().Length);
        }
    }
}