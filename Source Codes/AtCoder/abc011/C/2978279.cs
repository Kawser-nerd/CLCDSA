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
            int addCnt = 0;
            int nowVal = 0;
            while (nowVal < n)//?????
            {
                int delta = 3;
                while (true)
                {
                    bool ng = false;
                    for (int i = 0; i < 3; i++)
                    {
                        if (nowVal + delta == ngs[i])
                        {
                            delta--;
                            ng = true;
                            break;
                        }
                    }
                    if (ng) continue;
                    else break;
                }
                if (delta == 0)
                {
                    Console.WriteLine("NO");
                    return;
                }
                nowVal += delta;
                addCnt++;
                //Console.WriteLine(nowVal);
            }

            if (addCnt <= 100)
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