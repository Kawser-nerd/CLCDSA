using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace ZurichProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            //const string fileName = "test";
            //const string fileName = "A-small-attempt0";
            const string fileName = "A-large";
            string DataFolder = @"C:\Projects\CSharp\CodeJam2008\ZurichProblemA\Data\";
            StreamReader sr = File.OpenText(DataFolder + fileName + ".in");
            using (StreamWriter sw = File.CreateText(DataFolder + fileName + ".out"))
            {
                int caseCount = int.Parse(sr.ReadLine());
                for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                {
                    //int turnaround = int.Parse(sr.ReadLine());
                    string[] s = sr.ReadLine().Split(' ');
                    int xA1 = int.Parse(s[0]) - int.Parse(s[2]);
                    int yA1 = int.Parse(s[1]) - int.Parse(s[3]);
                    int xB1 = int.Parse(s[4]) - int.Parse(s[2]);
                    int yB1 = int.Parse(s[5]) - int.Parse(s[3]);
                    
                    int xC1 = int.Parse(s[2]);
                    int yC1 = int.Parse(s[3]);


                    s = sr.ReadLine().Split(' ');
                    int xA2 = int.Parse(s[0]) - int.Parse(s[2]);
                    int yA2 = int.Parse(s[1]) - int.Parse(s[3]);
                    int xB2 = int.Parse(s[4]) - int.Parse(s[2]);
                    int yB2 = int.Parse(s[5]) - int.Parse(s[3]);

                    int xC2 = int.Parse(s[2]);
                    int yC2 = int.Parse(s[3]);

                    int D = (xA1 - xA2) * (yB1 - yB2) - (xB1 - xB2) * (yA1 - yA2);
                    int aC = (xC2 - xC1) * (yB1 - yB2) - (yC2 - yC1) * (xB1 - xB2);
                    int bC = (yC2 - yC1) * (xA1 - xA2) - (xC2 - xC1) * (yA1 - yA2);

                    string res = "";
                    if (D == 0)
                    {
                        if (aC == 0 && bC == 0)
                            res = xC1 + " " + yC1;
                        else
                            res = "No Solution";
                    }
                    else
                    {

                        double a = (double)aC / D;
                        double b = (double)bC / D;
                        if (a + b <= 1 && a >= 0 && b >= 0)
                        {
                            double x = xC2 + xA2 * a + xB2 * b;
                            double y = yC2 + yA2 * a + yB2 * b;
                            res = x.ToString("F8", CultureInfo.InvariantCulture) + " " + y.ToString("F8", CultureInfo.InvariantCulture);
                        }
                        else
                            res = "No Solution";
                    }
                    sw.WriteLine("Case #" + caseNumber.ToString() + ": " + res);
                }
            }

        }
    }
}
