using System;

namespace arc003_2
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string[] s = new string[n];
            for (int i = 0; i < n; i++)
            {
                char[] a = Console.ReadLine().ToCharArray();
                Array.Reverse(a);
                s[i] = new string(a);
            }
            Array.Sort(s);
            for (int i = 0; i < n; i++)
            {
                char[] a = s[i].ToCharArray();
                Array.Reverse(a);
                Console.WriteLine(new string(a));
            }
        }
    }
}