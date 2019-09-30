using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());

            for (int i = 0; i < T; i++)
            {

                Console.WriteLine("Case #{0}: {1}", i + 1, new Solver().Solve());
            }
        }
    }

    class Solver
    {



        public string Solve()
        {
            var nxy = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            int N = nxy[0];
            int X = Math.Abs(nxy[1]);
            int Y = nxy[2];

            if ((X + Y) % 2 != 0)
                return "0";

            int lvl = (X + Y) / 2;
            int dInLvl = 1;
            int from = 0;
            int to = 1;

            for (int i = 0; i < lvl; i++)
            {
                dInLvl += 4;
                from = to;
                to += dInLvl;
            }

            //border cases
            if (N <= from)
                return "0";
            if (N >= to)
                return "1";

            

            int dCount = N - from;

            if (X == 0)
            {
                if (N < to)
                    return "0";
                else
                    return "1";
            }
            

            if (Y >= dInLvl)
                return "0";

            if (dCount > (lvl * 2) + Y)
                return "1";

            return AtLeastXinNtrials(Y+1, dCount).ToString().Replace(',', '.');
        }

        double AtLeastXinNtrials(int X, int N)
        {
            double result = 1;
            for (int k = 0; k < X; k++)
            {
                result -= Newton(N, k) * Math.Pow(0.5, k) * Math.Pow(0.5, N - k);
            }

            return result;
        }

        double Newton(double n, double k)
        {
            double top = 1;
            for(int i=0;i<k;i++)
                top *= n-i;

            double bottom = 1;
            for(int i=2;i<=k;i++)
                bottom *= i;

            return top / bottom;
        }

        

    }
}
