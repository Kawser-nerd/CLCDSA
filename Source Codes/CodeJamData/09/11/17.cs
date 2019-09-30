using System;
using System.Globalization;
using System.Text;
using System.Collections.Generic;
using System.IO;


class Program
{
    static int[,] H = new int[11,3000];

    static int happy(int n, int b)
    {
        int sum = 0;
        while (n > 0)
        {
            sum += (n % b) * (n % b);
            n /= b;
        }
        if (sum == 1) return 1;
        
        if (H[b,sum]>=0)
        {
            return H[b,sum];
        }
        else
        {
            if (H[b, sum] == -2) { H[b, sum] = 0; return 0; }
            H[b, sum] = -2;
            int e  = happy(sum,b);
            H[b,sum] = e;
            return e;
        }
    }

    static void Main(string[] args)
    {

        string infile = "A-large.in";
        string outfile = "agysejt_large.out";
        //string infile = "A-small-attempt0.in";
        //string outfile = "A-small-attempt0.out";
        //string infile = "in.txt";
        //string outfile = "out.txt";

        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 3000; j++)
            {
                H[i, j] = -1;
            }
        }

        int[] min = new int[1 << 9];
        min[0]=2;
        // !!!!!!!!!!!!!!!!!!
        for (int i = 1; i <=9 ; i++)
        {
            Console.WriteLine("Bitcount: "+i);
            for (int j = 0; j < 1<<9; j++)
            {
                int c = 1;
                int db = 0;
                for (int k = 0; k < 9; k++)
                {
                    if ( (j & c) == c) db++;
                    c = c << 1;
                }
                if (db == i)
                {
                    int max = 0;
                    c = 1;
                    List<int> bases = new List<int>();
                    for (int k = 0; k < 9; k++)
                    {
                        if ((j & c) == c)
                        {
                            max = Math.Max(max, min[j ^ c]);
                            bases.Add(k + 2);
                        }
                        
                        c = c << 1;
                    }
                    int res = 0;
                    for (int jj = max; ; jj++)
                    {
                        bool jo = true;
                        for (int ii = bases.Count - 1; ii >= 0; ii--)
                        {
                            if (happy(jj, bases[ii]) != 1) { jo = false; break; }
                        }
                        if (jo) { res = jj; break; }
                    }
                    min[j] = res;
                    /*if (i > 7)
                    {
                        for (int ii = 0; ii < bases.Count; ii++)
                        {
                            Console.Write(bases[ii]+",");
                        }
                        Console.WriteLine("    " + res);
                    }*/

                }
            }
        }

        TextReader tr = new StreamReader(infile);
        TextWriter tw = new StreamWriter(outfile);
        int N = int.Parse(tr.ReadLine()  );
        string line;
        for (int iii = 0; iii < N; iii++)
        {
            string[] s= tr.ReadLine().Trim().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            List<int> bases = new List<int>();
            for (int i = 0; i < s.Length; i++)
            {
                bases.Add(int.Parse(s[i]));
            }
            
            /*int res=0;
            for (int j = 2;; j++)
            {
                bool jo = true;
                for (int i = bases.Count-1; i >=0; i--)
                {
                    if (happy(j, bases[i])!=1) { jo = false; break; }
                }
                if (jo) { res = j; break; }
            }*/
            int flag = 0;
            for (int i = 0; i < bases.Count; i++)
            {
                flag = flag | (1 << (bases[i] - 2));
            }
            tw.WriteLine("Case #{0}: {1}",iii+1,min[flag]);
            
        }

        

        tw.Close();
        tr.Close();
        Console.ReadLine();

        //Console.WriteLine((2.25).ToString(CultureInfo.InvariantCulture));
    }

}
