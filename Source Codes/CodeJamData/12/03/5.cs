using System;
using System.Collections.Generic;
using System.Linq;

class Recycled
{

    static int Compare(string s1, int i1, string s2, int i2)
    {
        int len = s1.Length;
        int len2 = s2.Length;
        if (len<len2) return -1;
        if (len>len2) return 1;
        for (int i=0; i!=len; ++i)
        {
            char ch1 = s1[(i1+i)%len];
            char ch2 = s2[(i2+i)%len];
            if (ch1 == ch2) continue;
            if (ch1 < ch2) return -1;
            return 1;
        }
        return 0;
    }
    static long SolveCase(int a, int b)
    {
        long count = 0;
        string bstr = b.ToString();
        for (int x=a; x<=b; ++x)
        {
            string xstr = x.ToString();
            for (int i=1; i!=xstr.Length; ++i)
            {
                if (xstr[i]=='0') continue;
                int cmpXstr = Compare(xstr,0,xstr,i);
                if (cmpXstr==0)
                {
                    // Our string is a repeating sequence. We must
                    // not continue or we'll just get repeats.
                    break;
                }
                if (cmpXstr>0)
                {
                    // Our cycled string is smalled than xstr.
                    continue;
                }
                if (Compare(xstr,i,bstr,0)>0)
                {
                    // Our cycled string is greater than bstr.
                    continue;
                }
                count += 1;

                //if (Compare(xstr,0,xstr,i)==0) break;
                //if (Compare(xstr,0,xstr
                //string cycled = xstr.Substring(i, xstr.Length-i) + xstr.Substring(0,i);
                //if (cycled[0]=='0')
                //    continue;
                //if (distinct.Contains(cycled))
                //    continue;
                //distinct.Add(cycled);
                //if (string.Compare(xstr,cycled)<0 && string.Compare(cycled,bstr)<=0)
                //{
                //    count += 1;
                //}
            }
        }
        return count;
    }
    static void Main()
    {
        int cases = int.Parse(Console.ReadLine().Trim());
        for (int i=0; i!=cases; ++i)
        {
            int[] values = Console.ReadLine().Trim().Split().Select(s=>int.Parse(s)).ToArray();
            int a = values[0];
            int b = values[1];
            long answer = SolveCase(a,b);
            Console.WriteLine("Case #{0}: {1}", i+1, answer);
        }
    }
}
