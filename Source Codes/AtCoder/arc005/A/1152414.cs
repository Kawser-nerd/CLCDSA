using System;

namespace arc005_1
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string input = Console.ReadLine();
            string[] s = input.Substring(0, input.Length - 1).Split();
            int x = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == "TAKAHASHIKUN" || s[i] == "Takahashikun" || s[i] == "takahashikun")
                {
                    x++;
                }
            }
            Console.WriteLine(x);
        }
    }
}