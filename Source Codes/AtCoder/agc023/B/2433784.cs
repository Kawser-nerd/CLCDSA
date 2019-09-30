using System;

namespace agc023_b
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            char[,] ban = new char[n, n];
            for (int i = 0; i < n; i++)
            {
                string s = Console.ReadLine();
                for (int j = 0; j < n; j++) ban[i, j] = s[j];
            }
            int ret = 0;
            for (int i = 0; i < n; i++)
            {
                bool flag = true;
                for (int k = 0; k < n && flag; k++)
                {
                    for (int l = 0; l < n && flag; l++)
                    {
                        if (ban[(k + i) % n, l % n] != ban[(l + i) % n, k % n])
                            flag = false;
                    }
                }
                if (flag) ret += n;
            }
            Console.WriteLine(ret);
        }
    }
}