using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace cookie
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader fin = new StreamReader("C:\\Users\\yzhao\\Downloads\\B-large.in");
            StreamWriter fout = new StreamWriter("out.txt");
            int t = int.Parse(fin.ReadLine());
            for (int casecount = 1; casecount <= t; casecount++)
            {
                string[] paraArray = fin.ReadLine().Split(' ');
                double c = double.Parse(paraArray[0]);
                double f = double.Parse(paraArray[1]);
                double x = double.Parse(paraArray[2]);
                double speed = 2;

                int k = (int)Math.Floor(x/c - 1/f);
                if (k < 1)
                {
                    fout.WriteLine("Case #" + casecount + ": " + x/speed);
                    continue;
                }

                double totaltime = 0;
                for (int i = 0; i < k; i++)
                    totaltime += c/(speed + i*f);
                totaltime += x/(speed + k*f);
                double temptotaltime = 0;
                for (int i = 0; i < k - 1; i++)
                    temptotaltime += c / (speed + i * f);
                temptotaltime += x / (speed + (k - 1) * f);
                if (temptotaltime < totaltime) totaltime = temptotaltime;
                fout.WriteLine("Case #" + casecount + ": " + totaltime);
            }
            fin.Close();
            fout.Close();
        }
    }
}
