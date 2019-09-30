using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;

namespace AlienLang
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader inFile = new StreamReader("dan.in");
            StreamWriter outFile = new StreamWriter("out.txt");
            string light_status = "";
            
            int num_cases = Convert.ToInt32(inFile.ReadLine());


            long Xmin;
            long Xmax;
            long Ymin;
            long Ymax;

            for (int c = 0; c < num_cases; c++)
            {
                string line = inFile.ReadLine();

                Xmin = Convert.ToInt32(line.Split(' ')[0]);
                Xmax = Convert.ToInt32(line.Split(' ')[1]);
                Ymin = Convert.ToInt32(line.Split(' ')[2]);
                Ymax = Convert.ToInt32(line.Split(' ')[3]);

                long num = caculate(Xmin, Xmax, Ymin, Ymax) + caculate(Ymin, Ymax, Xmin, Xmax);
                outFile.WriteLine("Case #" + (c + 1) + ": " + num);
            }

            
            outFile.Flush();
            outFile.Close();

        }

        public static long caculate(long Amin, long Amax, long Bmin, long Bmax)
        {
            long num = 0;

            for (long a = Amin; a <= Amax; a++)
            {
                double alpha = a /(1.61803398874989484820458683436563811);
                long x = (long)Math.Floor(alpha);

                if (x < Bmin)
                    num += 0;
                else
                {
                    if (x < Bmax)
                        num += (x - Bmin) + 1;
                    else
                        num += (Bmax - Bmin) + 1;
                }
            }
            return num;
        }

    }
}
