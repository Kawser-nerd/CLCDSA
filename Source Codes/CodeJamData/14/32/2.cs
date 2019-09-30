using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;



class Program
{

    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader("D:\\in.in");
        StreamWriter sw = new StreamWriter("D:\\out.out");
        sw.AutoFlush = true;
        int n = int.Parse(sr.ReadLine());
        Console.WriteLine(n);
        for (int i = 0; i < n; i++)
        {
            sw.WriteLine("Case #" + (i + 1).ToString() + ": " + Solution(sr));
            Console.WriteLine(i);
        }
        sw.Close();
        sr.Close();
        Console.WriteLine("Finished");
        Console.ReadLine();
    }


    static bool good(string v, char a)
     {
         int r = 0;
         while (r <v.Length &&v[r] == a) r++;
         if (r == v.Length)
             return true; 
        while (r < v.Length && v[r] != a) r++;
         if (r == v.Length)
             return true;
         if (v[0] == a)
             return false;
         while (r < v.Length && v[r] == a) r++;
         if (r == v.Length)
             return true;
         while (r < v.Length && v[r] != a) r++;
         if (r == v.Length)
             if (r == v.Length)
                 return true;
         return false;
     }

    static void movecarts(char a, List<string> p)
    {
        string A = a.ToString();
        string first = "";
        string last = "";
        long varian = 1;
        long num = 1;
        bool any = false;
        for (int i = 0; i < p.Count; i++)
        {
            if (p[i].Contains(A))
            {
                any = true;
                string s = p[i];
                p.RemoveAt(i);
                i--;
                if (!good(s,a))
                    throw new Exception("alma");

                if (s[0] != a)
                {
                    if (first != "")
                        throw new Exception("alma");
                    first = s;
                }else
                if (s[s.Length-1] != a)
                {
                    if (last != "")
                        throw new Exception("alma");
                    last = s;
                }
                else
                {
                    varian *= num;
                    varian %= mod;
                    num++;
                }
            }
        }
        if (!any)
            return;
        if (first != "" && first[first.Length - 1] != a && num > 1)
            throw new Exception("alma");

        first += last;
        if (!good(first, a))
            throw new Exception("alma");
        p.Add(first);
        res *= varian;
        res %= mod;
    }

    const long mod = 1000000007;
    static long res = 1;
    static string Solution(StreamReader sr)
    {
        sr.ReadLine();
        List<string> p = new List<string>(sr.ReadLine().Split(' '));


        res = 1;

        try
        {
            for (char i = 'a'; i <= 'z'; i++)
            {
                movecarts(i, p);
            }


            long varian = 1;
            long num = 1;

            foreach (var item in p)
            {
                 varian *= num;
                    varian %= mod;
                    num++;
            }

            res *= varian;
            res %= mod;

            return res.ToString();

        }catch (Exception e)
        {
            return "0";
        }
    }
}