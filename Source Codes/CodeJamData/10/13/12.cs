using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Number_Game
{
    class Program
    {

        static int winning = 0;
        static void Main(string[] args)
        {
            bool consoleOut = false;

            string caseFile = "small";
            string outFile = "out." + caseFile + ".txt";
            string inFile = "in." + caseFile + ".txt";
            System.IO.StreamReader sr = new System.IO.StreamReader(inFile);
            System.IO.TextWriter sw = consoleOut ? System.Console.Out : new System.IO.StreamWriter(outFile);

            int tests = int.Parse(sr.ReadLine());
            for (int test = 0; test < tests; test++)
            {
                string[] tmp = sr.ReadLine().Split(' ');
                int a1 = int.Parse(tmp[0]);
                int a2 = int.Parse(tmp[1]);
                int b1 = int.Parse(tmp[2]);
                int b2 = int.Parse(tmp[3]);
                winning = 0;
                for (int i = a1; i <= a2; i++)
                    for (int j = b1; j <= b2; j++)
                    {
                        
                        rec(i, j, true, true);
                    }
                sw.WriteLine("Case #"+(test+1)+": "+ winning.ToString());

            }


            if (consoleOut)
                System.Console.ReadLine();
            sw.Close();
        }

        static bool rec(int a, int b, bool Ayra, bool root)
        {
            if (a <= 0 || b <= 0)
                return Ayra;
            int kmax = 0;
            if (b > a)
            {
                int tmp = b;
                b = a;
                a = tmp;
            }
            kmax = a / b;

            bool res = !Ayra;
            int res2 = 0;
            for (int k = kmax; k >0; k--)
            {
                bool won = rec(a - k * b, b, !Ayra, false);
                if (root && won)
                    winning++;
                if (!Ayra)
                    res &= won;
                else
                    res |= won;
                if (!Ayra && !res)
                    return res;
                if (Ayra && res)
                    return res;
            }

            return res;
        }
    }
}
