using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.IO;

namespace codejam2013
{
    public class B
    {
        public void Run()
        {
           //string filename = "B-sample";
            string filename = "B-small";
            //string filename = "B-large";

            var lines = File.ReadAllLines(filename + ".in");
            int r = 0;
            var Ts = lines[r++];
            var T = int.Parse(Ts);
            var file = new System.IO.StreamWriter(filename + ".out");
            for (int i = 0; i < T; i++)
            {
                var l1s = lines[r++];
                var l1=l1s.Split(' ').Select(int.Parse).ToArray();
                int N = l1[0];
                int X = l1[1];
                int Y = l1[2];
                var res = Result(N,X,Y);

                file.WriteLine("Case #" + (i + 1) + ": " + res.ToString(CultureInfo.InvariantCulture).Replace(",","."));
            }
            file.Close();
        }



        public double Result(int n, int x,int y)
        {
            int h = Math.Abs(x);
            int z = h + y;
            
            var ext = (z+1)*(z + 2)/2;
            if (x==0)
            {
                return (n >= ext) ? 1 : 0;
            }
            var inclusi = z * (z - 1) / 2;
            int nuovi = n - inclusi;
            if (nuovi<0)
            {
            }
            return calcola(nuovi,z,y+1);
        }

        private double calcola(int tentativi, int errori, int validi)
        {
            double res = 0;
            if (validi == 0) return 1;
            if (tentativi == 0) return 0;
            if(errori+validi==0) return 0;
            int div = 0;
            if (errori > 0)
            {
                div++;
                res += calcola(tentativi - 1, errori-1, validi);
            }
            if (validi > 0)
            {
                div++;
                res += calcola(tentativi - 1, errori, validi-1);
            }
            
            return res/div;
        }

    }
}
