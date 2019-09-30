using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace GCJApp
{
    class Program
    {
        static int ret;

        static void Main(string[] args)
        {
            TextWriter tw = new StreamWriter("C:\\myStuff\\GCJ\\Data\\B-small.out");

            TextReader tr = new StreamReader("C:\\myStuff\\GCJ\\Data\\B-small-attempt0.in");

            int N = Int32.Parse(tr.ReadLine());

            string s;

            for (int i = 1; i <= N; i++)
            {

                s = (tr.ReadLine());
                ret = 0;

                cover(s, 0L);
                
                
                tw.WriteLine("Case #" + (i) + ": " + ret);
                //tw.WriteLine("Case #" + (i) + ": " + r2);
            }
            tw.Flush();
            tw.Close();

        }

        static void cover(string s, long val)
        {
            if (s.Length == 0)
            {
                if (isUgly(val))
                    ret++;
                return;
            }
            long i = long.Parse(s[s.Length - 1].ToString());
            string ssub = s.Substring(0, s.Length - 1);
            if(ssub.Length>0)
                cover(ssub, val - i);
            cover(ssub, val + i);
            cover2(s, val, 2);
            return;
        }

        static void cover2(string s, long val,int len)
        {
            if (len > s.Length) return;
            if (s.Length == len)
            {
                if (isUgly(long.Parse(s)+val))
                    ret++;
                return;
            }
            long i = long.Parse(s.Substring(s.Length-len));
            string ssub = s.Substring(0, s.Length - len);
            cover(ssub, val - i);
            cover(ssub, val + i);
            cover2(s, val, len+1);
            return;
        }

        static bool isUgly(long val)
        {
            if (val < 0) val = 0 - val;
            if (val == 0) return true;
            if (val % 2 == 0) return true;
            if (val % 3 == 0) return true;
            if (val % 5 == 0) return true;
            if (val % 7 == 0) return true;
            return false;
        }


    }
}
