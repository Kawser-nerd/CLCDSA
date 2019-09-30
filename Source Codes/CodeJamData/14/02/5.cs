using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;


using System.IO;

namespace CookieClickerAlpha
{
    class Program
    {
        static void Main(string[] args)
        {
            //StreamReader sr = new StreamReader("D:\\a.txt");
            //StreamWriter sw = new StreamWriter("D:\\b.txt");

            //StreamReader sr = new StreamReader("D:\\B-small-attempt0.in");
            //StreamWriter sw = new StreamWriter("D:\\B-small-attempt0.out");

            StreamReader sr = new StreamReader("D:\\B-large.in");
            StreamWriter sw = new StreamWriter("D:\\B-large.out");

            int numTestCases = Convert.ToInt32(sr.ReadLine());

            for (int i = 0; i < numTestCases; i++)
            {
                string[] str = sr.ReadLine().Split(' ');

                double C = Double.Parse(str[0]);
                double F = Double.Parse(str[1]);
                double X = Double.Parse(str[2]);


                int numFarms = 0;
                double time = X / 2.0;
                double lastPurchaseTime = 0.0;
                while (true)
                {
                    lastPurchaseTime += C / (2.0 + numFarms * F);
                    numFarms++;

                    double expTime = lastPurchaseTime + X / (2.0 + numFarms * F);

                    if (expTime < time)
                    {
                        time = expTime;
                    }
                    else
                    {
                        break;
                    }
                }

                sw.Write("Case #{0}: ", i + 1);
                sw.Write(time);
                sw.WriteLine();

            }
            sw.Close();
        }

    }
}
