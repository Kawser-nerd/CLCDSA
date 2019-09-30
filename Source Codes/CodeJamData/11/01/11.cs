using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            int totalCase = Convert.ToInt32(Console.ReadLine());
            for (int curCase = 0; curCase < totalCase; ++curCase)
            {
                string[] str = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                int n = Convert.ToInt32(str[0]);
                int oPos = 1;
                int bPos = 1;
                int oTime = 0;
                int bTime = 0;
                int curTime = 0;
                for (int i = 0; i < n; ++i)
                {
                    int pos = Convert.ToInt32(str[i * 2 + 2]);
                    if (str[i * 2 + 1] == "O")
                    {
                        oTime += Math.Abs(oPos - pos);
                        if (oTime < curTime) oTime = curTime;
                        curTime = ++oTime;
                        oPos = pos;
                    }
                    else
                    {
                        bTime += Math.Abs(bPos - pos);
                        if (bTime < curTime) bTime = curTime;
                        curTime = ++bTime;
                        bPos = pos;
                    }
                }
                Console.WriteLine("Case #{0}: {1}", curCase + 1, curTime);
            }
        }
    }
}
