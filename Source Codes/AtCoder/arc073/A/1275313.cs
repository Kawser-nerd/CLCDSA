using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class AC073C
    {
#if true
        static void Main(string[] args)
        {
            string s1 = Console.ReadLine();
            string s2 = Console.ReadLine();

            Console.WriteLine(funcMain(s1,s2));
#if DEBUG
            Console.ReadKey();
#endif
        }

#else
        static void Main(string[] args)
        {
            test();
        }
#endif

        static private string funcMain(string arg1, string arg2)
        {
            string[] bufarray;
            bufarray = arg1.Split();
            int Ninzu = int.Parse(bufarray[0]);
            long OneTime = long.Parse(bufarray[1]);
            long TotalTime = 0;
            long NowTime = 0;

            foreach (long t in arg2.Split().Select(f => long.Parse(f)))
            {
                TotalTime += Math.Min(t - NowTime,OneTime);
                NowTime = t;
            }
            TotalTime += OneTime;
            return TotalTime.ToString();
        }

        static private void test()
        {
            string arg1, arg2;
            arg1 = "2 4";
            arg2 = "0 3";
            Console.WriteLine("7" == funcMain(arg1, arg2));
            arg1 = "2 4";
            arg2 = "0 5";
            Console.WriteLine("8" == funcMain(arg1, arg2));
            arg1 = "4 1000000000";
            arg2 = "0 1000 1000000 1000000000";
            Console.WriteLine("2000000000" == funcMain(arg1, arg2));
            arg1 = "1 1";
            arg2 = "0";
            Console.WriteLine("1" == funcMain(arg1, arg2));
            arg1 = "9 10";
            arg2 = "0 3 5 7 100 110 200 300 311";
            Console.WriteLine("67" == funcMain(arg1, arg2));
            Console.ReadKey();
        }

    }
}