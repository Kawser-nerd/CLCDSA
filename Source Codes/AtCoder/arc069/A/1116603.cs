using System;
using System.Linq;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using System.Text;
 
public class Program
{
    public void Proc() {
        Reader.IsDebug = false;
        long[] inpt = Reader.ReadLine().Split(' ').Select(a=>long.Parse(a)).ToArray();
        this.SCount = inpt[0];
        this.CCount = inpt[1];

        long s = this.GetSCount(this.SCount, this.SCount + this.CCount / 2);
        long ans = GetCount(s);
        Console.WriteLine(ans);
    }

    private long GetSCount(long min, long max) {

        long mid1 = min + (max-min)/3;
        long mid2 = min + ((max-min)*2/3);

        long[] vals = new long[]{GetCount(min), GetCount(mid1), GetCount(mid2), GetCount(max)};
        long v = vals.Max();

        if(max-min <= 3) {
            if(vals[0] == v) {
                return min;
            } else if(vals[1] == v) {
                return mid1;
            } else if(vals[2] == v) {
                return mid2;
            }
            return max;
        }

        if(vals[0] == v) {
            return this.GetSCount(min, mid1);
        } else if(vals[1] == v) {
            return this.GetSCount(min, mid2);
        } else if(vals[2] == v) {
            return this.GetSCount(mid1, max);
        } else {
            return this.GetSCount(mid2, max);
        }

    }
    private long GetCount(long s) {
        long makeS = s-this.SCount;

        long c = CCount - (makeS*2);

        if(c < 0) {
            return 0;
        }

        return Math.Min(s, c/2);

    }

    private long SCount;
    private long CCount;

    public class Reader {
        public static bool IsDebug = true;
        private static System.IO.StringReader SReader;
        private static string InitText = @"



12345 678901




";
        public static string ReadLine() {
            if(IsDebug) {
                if(SReader == null) {
                    SReader = new System.IO.StringReader(InitText.Trim());
                }
                return SReader.ReadLine();
            } else {
                return Console.ReadLine();
            }
        }
    }
    public static void Main(string[] args)
    {
        Program prg = new Program();
        prg.Proc();
    }
}