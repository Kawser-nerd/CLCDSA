using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.C_Challenge
{
    class ABC_011
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            var ngs = new int[3];
            bool nEqNg = false;
            for (int i = 0; i < 3; i++)
            {
                ngs[i] = int.Parse(Console.ReadLine());
                if (ngs[i] == n) nEqNg = true;
            }
            if (nEqNg)
            {
                Console.WriteLine("NO");
                return;
            }

            Array.Sort(ngs);
            int nowVal = 0;
            for(int i=0;i<100;i++)//?????
            {
                int delta = 3;
                for (int j = 2; j >=0; j--)
                {
                    if (nowVal + delta == ngs[j])
                    {
                        delta--;
                    }
                }
                nowVal += delta;
            }

            if (nowVal>=n)
            {
                Console.WriteLine("YES");
            }
            else
            {
                Console.WriteLine("NO");
            }
        }
    }
}