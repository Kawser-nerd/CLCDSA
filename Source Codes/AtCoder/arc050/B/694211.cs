using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

class Program
{
    public void Proc()
    {
        Reader.IsDebug = false;
        string[] inpt = Reader.ReadLine().Split(' ');
        this.R = long.Parse(inpt[0]);
        this.B = long.Parse(inpt[1]);


        inpt = Reader.ReadLine().Split(' ');
        this.X = long.Parse(inpt[0]);
        this.Y = long.Parse(inpt[1]);

        /*
         * x ?????? 1 ???????????
        1 ?????? y ??????????? */


        long ans = this.CanCreate(0, this.R + this.B);
        Console.WriteLine(ans.ToString("############################################0"));
    }



    private long CanCreate(long min, long max)
    {
        long mid = (min + max) / 2;

        if (this.R - mid < 0 || this.B - mid < 0)
        {
            return CanCreate(min, mid);
        }
        long tmp = (this.R - mid) / (X - 1) + (this.B - mid) / (this.Y - 1);

        if (tmp >= mid)
        {
            if (max - mid <= 1)
            {
                return mid;
            }
            else
            {
                return CanCreate(mid, max);
            }

        }
        else 
        {
            if (mid - min <= 0)
            {
                return min;
            }
            else
            {
                return CanCreate(min, mid);
            }
        }
    }

    private long B;
    private long R;

    private long X;
    private long Y;




    public class Reader
    {
        public static bool IsDebug = true;
        private static String PlainInput = @"

100000 10
2 2


 
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
        public static int[] GetInt(char delimiter = ' ', bool trim = false)
        {
            string inptStr = ReadLine();
            if (trim)
            {
                inptStr = inptStr.Trim();
            }
            string[] inpt = inptStr.Split(delimiter);
            int[] ret = new int[inpt.Length];
            for (int i = 0; i < inpt.Length; i++)
            {
                ret[i] = int.Parse(inpt[i]);
            }
            return ret;
        }
    }
    static void Main()
    {
        Program prg = new Program();
        prg.Proc();
    }
}