using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;
using System.Linq;
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


    static int[] min = new int[1000 * 1000];
    static int[] max = new int[1000 * 1000];


    static int[] V = new int[1000 * 1000 * 4];


    static string Solution(StreamReader sr)
    {
        string[] tmp = sr.ReadLine().Split(' ');
        long N = long.Parse(tmp[0]);
        int D = int.Parse(tmp[1]);
        tmp = sr.ReadLine().Split(' ');
        long S = long.Parse(tmp[0]);
        int s = (int)S;
        long AS = long.Parse(tmp[1]);
        long CS = long.Parse(tmp[2]);
        long RS = long.Parse(tmp[3]);

        tmp = sr.ReadLine().Split(' ');
        long M = long.Parse(tmp[0]);
        long AM = long.Parse(tmp[1]);
        long CM = long.Parse(tmp[2]);
        long RM = long.Parse(tmp[3]);

        min[0] = (int)S;
        max[0] = (int)S;

        for (int i = 0; i < V.Length; i++)
        {
            V[i] = 0;
        }

        V[s - D + 1000 * 1000]++;
        V[s + D + 1000 * 1000 + 1]--;


        

        for (int i = 1; i < N; i++)
        {
            S = (S * AS + CS) % RS;
            M = (M * AM + CM) % RM;
            long m = M % i;

          ////  Console.WriteLine("{2} manager {0} salary {1}", m, S, i);

            min[i] = (int)Math.Min(min[m], S);
            max[i] = (int)Math.Max(max[m], S);

            if (min[i] + 1000 * 1000 + 1 > max[i] - D + 1000 * 1000)
            {
                V[min[i] + 1000 * 1000 + 1]--;
                V[max[i] - D + 1000 * 1000]++;
            }
        }


        int r = 0;
        int c = 0;
        foreach (var item in V)
        {
            c += item;
            r = Math.Max(r, c);
        }

        //Console.WriteLine();
        //for (int i = 1000 * 1000 + 0; i < 1000 * 1000 +25; i++)
        //{
        //    Console.WriteLine("{0} {1}", i - 1000 * 1000, V[i]);
        //}
        //Console.WriteLine();


        return (r).ToString();
    }
}