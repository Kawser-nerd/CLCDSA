using System;
using System.Collections.Generic;
using static System.Console;
using System.Linq;
using System.IO;

namespace ConsoleApp2
{
    class Program {
        static decimal C(int a,int b) {
            decimal res = 1;
            for (int i = 0; i < b; i++) {
                res *= (a - i);
                res /= (i + 1);
            }
            return res;
        }
        static void Main(string[] Args) {
            Console.SetIn(new StreamReader(Console.OpenStandardInput(8192)));

            var l = new List<string>(ReadLine().Split(' ')).Select(int.Parse).ToList();
            int N = l[0];
            int A = l[1];
            int B = l[2];

            var Value = new List<string>(ReadLine().Split(' ')).Select(long.Parse).GroupBy(i => i).OrderBy(x => -x.Key).ToList();

            /*
            foreach (var e in Value) {
                WriteLine(e.Key + ":" + e.Count());
            }
            */            

            decimal res = 0;
            decimal ave = 0; /* ???????? */

            if (A <= Value[0].Count()) {
                for (int i = A; i <= B; i++) {
                    //WriteLine(String.Format("{0}C{1} = {2}", A, Value[0].Count(), C(Value[0].Count(), i)));
                    res += C(Value[0].Count(), i);
                }
                ave = Value[0].Key;
            } else {
                int i;
                int A_ = A;
                for (i = 0; A >= Value[i].Count(); i++) {
                    A -= Value[i].Count(); /* ??? */
                    ave += Value[i].Key * Value[i].Count();
                }
                res = C(Value[i].Count(), A);
                ave += Value[i].Key * A;
                ave /= A_;
            }
            WriteLine(ave);
            WriteLine(res);

            ReadLine();
        }
    }
}