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
        //DateTime t = DateTime.Now;
        //for (int k = 0; k < 1; k++)
        //{
        //    Random r = new Random();

        //    int[] v = new int[1000];
        //    a = new int[1000];
        //    for (int i = 0; i < v.Length; i++)
        //    {
        //        v[i] = r.Next(int.MaxValue);
        //    }
        //    for (int i = 0; i < v.Length; i++)
        //    {
        //        check(v, i);
        //    }
        //}
        //Console.WriteLine((DateTime.Now - t).TotalMilliseconds);
        //return;


        StreamReader sr = new StreamReader("D:\\CodeJam\\in.in");
        StreamWriter sw = new StreamWriter("D:\\CodeJam\\out.txt");
        sw.AutoFlush = true;
        string number = sr.ReadLine();
        int n = int.Parse(number);//convert
        Console.WriteLine(n);
        for (int i = 0; i < n; i++)
        {
            string result = Solution(sr);
            sw.WriteLine("Case #" + (i + 1).ToString() + ": " + result);
            Console.WriteLine(i);
        }
        sw.Close();
        sr.Close();
        Console.WriteLine("Finished");
        Console.ReadLine();
    }




    static int[] a;
    static int maxpos = 0;

    static int calc(LinkedList<int> A)
    {
        int r = 0;
        while (A.Count > 0)
        {
            int min = int.MaxValue;
            int minp = -1;
            int ind = 0;
            foreach (var item in A)
            {
                if (item < min)
                {
                    min = item;
                    minp = ind;                    
                }
                ind++;
            }
            A.Remove(min);
            r += Math.Min(minp, A.Count-minp);
        }
        return r;

    }

    static int check(int[] v)
    {        



        LinkedList<int> A = new LinkedList<int>();
        for (int i = 0; i < v.Length; i++)
        {
            A.AddLast(v[i]);
        }

        return calc(A);
        

    }

    static string Solution(StreamReader sr)
    {
        sr.ReadLine();
        string[] t = sr.ReadLine().Split();
        int[] v = new int[t.Length];
        for (int i = 0; i < t.Length; i++)
        {
            v[i] = int.Parse(t[i]);
        }
        a = new int[v.Length];

        int max = -1;
        for (int i = 0; i < v.Length; i++)
        {
            if (v[i] > max)
            {
                max = v[i];
                maxpos = i;
            }
        }



        int r = check(v);
        return r.ToString();

    }


}