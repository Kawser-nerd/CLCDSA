using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
        string inpt = Reader.ReadLine();
        this.aCount = new int[inpt.Length];
        this.cCount = new int[inpt.Length];
        this.hatenCount = new int[inpt.Length];

        if (inpt[0] == 'A')
        {
            this.aCount[0] = 1;
        }
        else if (inpt[0] == 'C')
        {
            this.cCount[0] = 1;
        }
        else if (inpt[0] == '?')
        {
            this.hatenCount[0] = 1;
        }
        for (int i = 1; i < inpt.Length; i++)
        {
            this.aCount[i] = this.aCount[i - 1];
            this.cCount[i] = this.cCount[i - 1];
            this.hatenCount[i] = this.hatenCount[i - 1];
            if (inpt[i] == 'A')
            {
                this.aCount[i]++;
            }
            else if (inpt[i] == 'C')
            {
                this.cCount[i]++;
            }
            else if (inpt[i] == '?')
            {
                this.hatenCount[i]++;
            }
        }

        long ans = 0;
        for (int i = 1; i < inpt.Length - 1; i++)
        {
            if (inpt[i] != '?' && inpt[i] != 'B')
            {
                continue;
            }
            long a = aCount[i - 1];
            long c = cCount[inpt.Length - 1];
            c -= cCount[i];
            long other = hatenCount[i - 1];
            long other2 = hatenCount[inpt.Length - 1];
            other2 -= hatenCount[i];
            long add = a * c;
            add = add % mod;
            add = add * GetTrip(other);
            add = add % mod;
            add = add * GetTrip(other2);
            add = add % mod;
            long add2 = other * c;
            add2 = add2 % mod;
            add2 = add2 * GetTrip(Math.Max(other - 1, 0));
            add2 = add2 % mod;
            add2 = add2 * GetTrip(other2);
            add2 = add2 % mod;
            long add3 = a * other2;
            add3 = add3 % mod;
            add3 = add3 * GetTrip(other);
            add3 = add3 % mod;
            add3 = add3 * GetTrip(Math.Max(0, other2 - 1));
            add3 = add3 % mod;
            long add4 = other * other2;
            add4 = add4 % mod;
            add4 = add4 * GetTrip(Math.Max(other - 1, 0));
            add4 = add4 % mod;
            add4 = add4 * GetTrip(Math.Max(other2 - 1, 0));
            add4 = add4 % mod;
            ans += add + add2 + add3 + add4;
            ans = ans % mod;
        }
        Console.WriteLine(ans);
    }
    long mod = 1000000000 + 7;

    long[] dic = new long[100000];
    private long GetTrip(long num) {
        if(dic[num] > 0) {
            return dic[num];
        }
        if(num == 0) {
            return 1;
        }
        long ans = GetTrip(num - 1) * 3;
        ans = ans % mod;
        dic[num] = ans;
        return ans;
    }

    int[] aCount;
    int[] cCount;
    int[] hatenCount;


    public class Reader
    {
        static StringReader sr;
        public static bool IsDebug = false;
        public static string ReadLine()
        {
            if (IsDebug)
            {
                if (sr == null)
                {
                    sr = new StringReader(InputText.Trim());
                }
                return sr.ReadLine();
            }
            else
            {
                return Console.ReadLine();
            }
        }
        private static string InputText = @"




????C?????B??????A???????


";
    }

    public static void Main(string[] args)
    {
#if DEBUG
        Reader.IsDebug = true;
#endif
        Program prg = new Program();
        prg.Proc();
    }
}