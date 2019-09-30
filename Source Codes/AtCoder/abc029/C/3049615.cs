using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.C_Challenge
{
    class ABC_029
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int allPat = (int)Math.Pow(3, n);
            for (int i = 0; i < allPat; i++)
            {
                var chars = new char[n];
                int val = i;
                for (int j = 0; j < n; j++)
                {
                    switch (val % 3)
                    {
                        case 0:
                            chars[j] = 'a';
                            break;
                        case 1:
                            chars[j] = 'b';
                            break;
                        case 2:
                            chars[j] = 'c';
                            break;
                    }
                    val /= 3;
                }
                Array.Reverse(chars);
                Console.WriteLine(chars);
            }
        }
    }
}