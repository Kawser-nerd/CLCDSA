using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

class Program
{
    public void Proc()
    {
        Reader.IsDebug = false;
        this.Range = long.Parse(Reader.ReadLine());

        long ans = GetAns(1, this.Range);

        Console.WriteLine(ans);


        
    }

    private long Range = 0;

    private long GetAns(long min, long max)
    {
        if (max - min <= 1)
        {
            if (CanReach(min))
            {
                return min;
            }
            return max;
        }
        long mid = (min + max) / 2;
        if (CanReach(mid))
        {
            return GetAns(min, mid);
        }
        else
        {
            return GetAns(mid, max);
        }
    }

    private bool CanReach(long val)
    {
        return (val * (val + 1) / 2) >= this.Range;
    }



    public class Reader
    {
        public static bool IsDebug = true;
        private static String PlainInput = @"


11


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