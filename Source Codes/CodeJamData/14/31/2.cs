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

     static public long GCD(long a, long b)
     { if (b == 0) return a; return GCD(b, a % b); }



     static string Solution(StreamReader sr)
     {
         string[] t = sr.ReadLine().Split('/');
         long a = long.Parse(t[0]);
         long b = long.Parse(t[1]);
         long c = GCD(a, b);
         a /= c;
         b /= c;
         if(a>b)
             return "impossible";

         long g = b;
         int v = 0;
         while(g>0)
         {
             if ((g & 1) == 1 && (g >> 1) > 0)
                 return "impossible";
             v++;
             g >>= 1;
         }

         while (a > 0)
         {
             v--;
             a >>= 1;
         }

         return v.ToString();
     }
}