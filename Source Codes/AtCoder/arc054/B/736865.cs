using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

class Program
{
    public void Proc()
    {
        Reader.IsDebug = false;
        double inpt = double.Parse(Reader.ReadLine());

        double ans = this.GetAns(0, inpt, inpt);
        Console.WriteLine(ans.ToString("##############0.####################"));
    }

    private double GetAns(double min, double max, double target)
    {
        double cal1 = calc(min, target);
        double cal3 = calc((min + max) / 2, target);
        double cal2 = calc(max, target);

        if (Math.Max(cal1,Math.Max(cal2,cal3)) - Math.Min(cal1, Math.Min(cal2, cal3)) < Math.Pow(10, -8))
        {
            return calc(min, target);
        }
        List<double> splt8 = new List<double>();

        double calMin = double.MaxValue;


        int minIdx = 0;



        for (double i = min; i <= max; i = Math.Min(max + (max - min) / 8, i + (max - min) / 8))
        {
            double cal = i + (target / Math.Pow(2, i / 1.5));
            if (cal < calMin)
            {
                calMin = cal;
                minIdx = splt8.Count;
            }
            splt8.Add(i);

        }

        if (minIdx == 0)
        {
            return this.GetAns(min, splt8[1], target);
        }
        else if (minIdx == splt8.Count - 1)
        {
            return this.GetAns(splt8[minIdx - 1], splt8[minIdx], target);
        }
        else
        {
            return this.GetAns(splt8[minIdx - 1], splt8[minIdx + 1], target);
        }
    }

    private double calc(double num, double target)
    {
        return num + (target / Math.Pow(2, num / 1.5));
    }

    

    public class Reader
    {
        public static bool IsDebug = true;
        private static String PlainInput = @"
 

1000000000000000000.0000

 
";
        private static System.IO.StringReader Sr = null;
        public static string ReadLine()
        {
            if (IsDebug)
            {
                if (Sr == null)
                {
                    Sr = new System.IO.StringReader(PlainInput.Trim());
                }
                return Sr.ReadLine();
            }
            else
            {
                return Console.ReadLine();
            }
        }

    }
    static void Main()
    {
        Program prg = new Program();
        prg.Proc();
    }
}