using System;
using System.Linq;

namespace arc006_2
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] n = new int[x[0]];
            for (int i = 0; i < x[0]; i++) n[i] = i + 1;
            for (int i = 0; i < x[1]; i++)
            {
                string[] s = Console.ReadLine().Split('|');
                for (int j = 1; j < x[0]; j++)
                {
                    if (s[j] == "-")
                    {
                        int a = n[j - 1];
                        n[j - 1] = n[j];
                        n[j] = a;
                    }
                }
            }
            char[] last = Console.ReadLine().ToCharArray();
            Console.WriteLine(n[Array.IndexOf(last, 'o') / 2]);
        }
    }
}