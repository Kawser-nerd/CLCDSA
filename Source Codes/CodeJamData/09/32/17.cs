using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Windows.Forms;

namespace TaskSolution
{
    class Program
    {
        static void Main(string[] args)
        {
            char[] sep = { ' ' };
            
            TextReader tr = new StreamReader(Path.Combine(Path.GetDirectoryName(Application.ExecutablePath), "input.txt"));
            TextWriter tw = new StreamWriter(@"c:\output.txt");

            int caseMax = Convert.ToInt32(tr.ReadLine());
            for (int caseIndex = 0; caseIndex < caseMax; caseIndex++)
            {
                int solution = 0;
                double x = 0;
                double y = 0;
                double z = 0;
                double vx = 0;
                double vy = 0;
                double vz = 0;
                int n = Convert.ToInt32(tr.ReadLine());

                for (int f = 0; f < n; f++)
                {
                    string[] s = tr.ReadLine().Split(sep);
                    
                    double q0 = Convert.ToDouble(s[0]);
                    x = x + q0;

                    double q1 = Convert.ToDouble(s[1]);
                    y = y + q1;

                    double q2 = Convert.ToDouble(s[2]);
                    z = z + q2;

                    double q3 = Convert.ToDouble(s[3]);
                    vx = vx + q3;

                    double q4 = Convert.ToDouble(s[4]);
                    vy = vy + q4;

                    double q5 = Convert.ToDouble(s[5]);
                    vz = vz + q5;
                }
                double tmin;
                if (vx * vx + vy * vy + vz * vz == 0)
                {
                    tmin = 0;
                }
                else
                {
                    tmin = -(x * vx + y * vy + z * vz) / (vx * vx + vy * vy + vz * vz);
                }
                if (tmin < 0)
                    tmin = 0;
                double dmin = Math.Sqrt(Math.Pow(x + vx * tmin, 2) + Math.Pow(y + vy * tmin, 2) + Math.Pow(z + vz * tmin, 2))/ (double) n;




                Console.WriteLine(String.Format("Case #{0}: {1} {2}", caseIndex + 1, dmin.ToString("0.00000000").Replace(',','.'), tmin.ToString("0.00000000").Replace(',','.')));
                tw.WriteLine(String.Format("Case #{0}: {1} {2}", caseIndex + 1, dmin.ToString("0.00000000").Replace(',', '.'), tmin.ToString("0.00000000").Replace(',', '.')));
            }
            tw.Close();
            Console.WriteLine("Ready:)");
            Console.ReadLine();

        }
    }
}

