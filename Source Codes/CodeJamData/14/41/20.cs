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



    static string Solution(StreamReader sr)
    {
        string[] t2 = sr.ReadLine().Split(' ');
        int X = int.Parse(t2[1]);
        string[] t = sr.ReadLine().Split(' ');
        int[] v = new int[t.Length];
        for (int i = 0; i < t.Length; i++)
        {
            v[i] = int.Parse(t[i]);
        }
        Array.Sort(v);
        int r = 0;
        int e = v.Length - 1;
        int s = 0;

        while(e>s)
        {
            if(v[e]+v[s]<=X)
            {
                r++;
                e--;
                s++;
            }
            else
            {
                e--;
                r++;
            }
        }
        if (e == s)
            r++;
        return r.ToString();


    }

    
}