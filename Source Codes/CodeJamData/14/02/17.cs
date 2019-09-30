using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Jam
{
    class Program
    {
        string run(double c, double f, double x)
        {
            double ret=0;
            double rate =2;
            while (x / rate > c / rate + x/(rate+f) )
            {
                ret += c/rate;
                rate+=f;
            }
            ret += x / rate;
            return ret.ToString();
        }
        static void Main(string[] args)
        {
            using (StreamReader f = new StreamReader("B-large.in"))
            {
                using (StreamWriter sw = new StreamWriter("B-large.out"))
                {
                    int cases = Int32.Parse(f.ReadLine());
                    for (int n = 0; n < cases; n++)
                    {
                        
                        string[] tmp = f.ReadLine().Split(' ');

                        Program p = new Program();
                        string output = p.run(double.Parse(tmp[0]), double.Parse(tmp[1]), double.Parse(tmp[2]));

                        sw.WriteLine("Case #" + (n + 1).ToString() + ": " + output);
                    }
                }
            }

        }
    }
}
