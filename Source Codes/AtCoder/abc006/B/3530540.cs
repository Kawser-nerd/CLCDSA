using System;
using System.Collections.Generic;

namespace AtCoderConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            // ??????1???
            string input = Console.ReadLine();

            // n???
            int n = int.Parse(input);

            // ????????????3??List???
            List<long> a = new List<long>();
            a.Add(0);
            a.Add(0);
            a.Add(1);

            // 4??????(10007?????????)
            if (n >= 4)
            {
                for (int i = 4; i <= n; i++)
                {
                    a.Add(a[i - 4] % 10007 + a[i - 3] % 10007 + a[i - 2] % 10007);
                }
            }

            // n??10007??????
            long output = a[n - 1] % 10007;

            // ???????
            Console.WriteLine(output);
        }
    }
}