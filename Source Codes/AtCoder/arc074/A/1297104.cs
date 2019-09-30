using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

class Program
{
    public void Proc()
    {
        Reader.IsDebug = false;
        long[] inpt = Reader.ReadLine().Split(' ').Select(a => long.Parse(a)).OrderBy(a=>a).ToArray();

        long ans = inpt[0] * inpt[1];
        if (inpt.Any(a => a % 3 == 0))
        {
            ans = 0;
        }
        else 
        {
            long totalCount = inpt[0] * inpt[1];

            long baseSize = totalCount / 3;

            int start = Math.Max(0, (int)(baseSize/inpt[0])-2);
            for(int i = start; i<= Math.Min(start + 4, inpt[1]-1); i++) {
                long p1 = inpt[0]*i;
                long[][] list = Divide(inpt[0], inpt[1]-i);

                foreach(long[] item in list) {
                    long[] subList = item.Union(new long[]{p1}).ToArray();
                    ans = Math.Min(subList.Max()-subList.Min(), ans);
                }
            }
            start = Math.Max(0, (int)(baseSize/inpt[1])-2);
            for(int i = start; i<= Math.Min(start + 4, inpt[0]-1); i++) {
                long p1 = inpt[1]*i;
                long[][] list = Divide(inpt[0]-i, inpt[1]);

                foreach(long[] item in list) {
                    long[] subList = item.Union(new long[]{p1}).ToArray();
                    ans = Math.Min(subList.Max()-subList.Min(), ans);
                }
            }
        }
        Console.WriteLine(ans);
    }

    private long[][] Divide(long x, long y)
    {
        long[][] ret;
        long total = x * y;
        if (x % 2 == 0 || y%2 ==0)
        {
            ret = new long[1][];
            ret[0] = new long[] { total / 2, total / 2 };
            return ret;
        }
        long[] tmp1 = new long[] { (x / 2) * y, (x - (x / 2)) * y };
        long[] tmp2 = new long[] { (y / 2) * x, (y - (y / 2)) * x };
        ret = new long[2][];
        ret[0] = tmp1;
        ret[1] = tmp2;
        return ret;
    }


 


    public class Reader
    {
        public static bool IsDebug = true;
        private static String PlainInput = @"

100000 100000


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