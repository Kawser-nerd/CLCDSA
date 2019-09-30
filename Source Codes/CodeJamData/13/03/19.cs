using System;
using System.Collections.Generic;
using System.IO;
using System.Numerics;

namespace Fair_and_Square
{
    internal class Program
    {
        private static readonly List<BigInteger> pp = new List<BigInteger>();

        private static void Main(string[] args)
        {
            //string filename = @"sample.in.txt";
            //string filename = @"C-small-attempt0.in.txt";
            string filename = @"C-large-2.in.txt";

            //List<BigInteger> pp2 = new List<BigInteger>();
            //List<BigInteger> pp4 = new List<BigInteger>();

            for (long i = 1; i <= 100000; i++)
            {
                if (isp(i) && isp(i*i))
                {
                    pp.Add(new BigInteger(i*i));
                    //pp2.Add(i);
                }
            }

            List<BigInteger> pp1 = new List<BigInteger>();

            //BigInteger ppp;

            for(int l = 1; l<26 ;l++)
            {

                int max = 1 << l;
                for(uint i=0;i<max;i++)
                {
                    uint cb = countBits(i);
                    if (cb < 4)
                    {
                        string rrr = Convert.ToString(i, 2);
                        if (rrr.Length<l)
                        {
                            rrr = new string('0', l - rrr.Length) + rrr;
                        }
                        string lnum = "1" + rrr;
                        char[] rnumm = lnum.ToCharArray();
                        Array.Reverse(rnumm);
                        string rnum = new string(rnumm);

                        BigInteger p = BigInteger.Parse(lnum + rnum);
//pp4.Add(p);
                        //ppp = p*p;
                        //if (pp1.Contains(ppp))
                        //{
                        //    int k = 1;
                        //}
                        pp1.Add(p*p);
                        p = BigInteger.Parse(lnum +"1"+ rnum);
                        //pp4.Add(p);
                        //ppp = p * p;
                        //if (pp1.Contains(ppp))
                        //{
                        //    int k = 1;
                        //}
                        pp1.Add(p * p);

                        p = BigInteger.Parse(lnum + "0" + rnum);
                        //pp4.Add(p);
                        //ppp = p * p;
                        //if (pp1.Contains(ppp))
                        //{
                        //    int k = 1;
                        //}
                        pp1.Add(p * p);

                        if (cb<2)
                        {
                            p = BigInteger.Parse(lnum + "2" + rnum);
                            //pp4.Add(p);
                            //ppp = p * p;
                            //if (pp1.Contains(ppp))
                            //{
                            //    int k = 1;
                            //}
                            pp1.Add(p * p);
                        }
                    }
                }

                {
                    string lnum = "2" + new string('0', l);
                    string rnum = new string('0', l) + "2";
                    BigInteger p = BigInteger.Parse(lnum + rnum);
                    //pp4.Add(p);
                    //ppp = p * p;
                    //if (pp1.Contains(ppp))
                    //{
                    //    int k = 1;
                    //}
                    pp1.Add(p * p);
                    p = BigInteger.Parse(lnum + "0" + rnum);
                    //pp4.Add(p);
                    //ppp = p * p;
                    //if (pp1.Contains(ppp))
                    //{
                    //    int k = 1;
                    //}
                    pp1.Add(p * p);
                    p = BigInteger.Parse(lnum + "1" + rnum);
                    //pp4.Add(p);
                    //ppp = p * p;
                    //if (pp1.Contains(ppp))
                    //{
                    //    int k = 1;
                    //}
                    pp1.Add(p * p);
                }

            }

            pp1.Sort();
            //pp4.Sort();
            foreach (BigInteger bigInteger in pp1)
            {
                if (pp[pp.Count-1]<bigInteger)
                    pp.Add(bigInteger);
            }


            DateTime begin = DateTime.Now;
            DateTime current = DateTime.Now;

            using (var reader = new StreamReader(filename))
            {
                using (var writer = new StreamWriter(filename.Replace(".in.", ".out."), false))
                {
                    int n = int.Parse(reader.ReadLine());
                    for (int i = 1; i <= n; i++)
                    {
                        Console.Write("N=" + i + " Time=");
                        Process(i, reader, writer);
                        Console.WriteLine((DateTime.Now - current).ToString().Substring(4));
                        current = DateTime.Now;
                    }
                }
            }

            Console.WriteLine("Time=" + (DateTime.Now - begin));
            Console.ReadLine();
        }

        private static uint countBits(uint x)
        {
            // count bits of each 2-bit chunk
            x = x - ((x >> 1) & 0x55555555);
            // count bits of each 4-bit chunk
            x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
            // count bits of each 8-bit chunk
            x = x + (x >> 4);
            // mask out junk
            x &= 0xF0F0F0F;
            // add all four 8-bit chunks
            return (x*0x01010101) >> 24;
        }


        private static void Process(int C, TextReader reader, TextWriter writer)
        {
            string[] ss = reader.ReadLine().Split(' ');
            BigInteger A = BigInteger.Parse(ss[0]);
            BigInteger B = BigInteger.Parse(ss[1]);

            int count = 0;
            foreach (BigInteger i in pp)
            {
                if (i >= A && i <= B)
                    count++;
            }

            Console.WriteLine("Case #{0}: {1}", C, count);
            writer.WriteLine("Case #{0}: {1}", C, count);
        }

        private static bool isp(long n)
        {
            string s = n.ToString();
            if (s.Length == 1)
                return true;
            for (int i = 0; i < s.Length/2; i++)
            {
                if (s[i] != s[s.Length - 1 - i])
                    return false;
            }
            return true;
        }
    }
}