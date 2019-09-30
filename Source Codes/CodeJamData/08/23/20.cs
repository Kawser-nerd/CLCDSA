using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Collections;

class C
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(args[0]);
        long cases = long.Parse(sr.ReadLine().Trim());
        for (long cas = 1; cas <= cases; cas++)
        {
            int len = int.Parse(sr.ReadLine().Trim());
            int[] asked = ToIntArr(sr.ReadLine().Trim().Split(new char[] { ' ' }));

            bool[] done = new bool[len];
            int[] vals = new int[len];
            vals[0] = 1;
            done[0] = true;
            int left = len-1;
            int ptr = 0;
            for (int i = 2; i <= len; i++)
            {
                int toadd = (i) % left;
                if (toadd == 0)
                    toadd = i;
                int cnt = 0;
                while (cnt < toadd)
                {
                    if (ptr==-1 || done[ptr])
                        ptr = (ptr + 1) % len;
                    else
                    {
                        ptr = (ptr + 1) % len;
                        cnt++;
                    }
                }
                vals[(ptr+len-1)%len] = i;
                done[(ptr + len - 1) % len] = true;
                left--;
            }

            string ret = "";
            for (int i = 1; i < asked.Length; i++)
            {
                ret += vals[asked[i] - 1].ToString() + " ";
            }
            ret = ret.Trim();

            Console.WriteLine("Case #" + cas + ": "+ret);

        }
    }

    static int[] ToIntArr(string[] arg)
    {
        int[] ret = new int[arg.Length];
        for (int i = 0; i < arg.Length; i++)
            ret[i] = int.Parse(arg[i]);
        return ret;
    }
}

