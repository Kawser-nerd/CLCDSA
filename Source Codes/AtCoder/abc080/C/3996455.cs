using System;
using System.Collections.Generic;
using System.Linq;

namespace CSharpSample01
{
    
    class Program
    {

        static List<string> ss;

        //k???????
        //k??????str
        static void Me(int k, string str)
        {
            if (k == 10)
            {
                ss.Add(str);
                return;
            }

            Me(k + 1, str + "1");

            Me(k + 1, str + "0");            

        }
        
        

        static void Main(string[] args) 
        {

            int N = int.Parse(Console.ReadLine());
            int[,] f = new int[N, 10];
            int[,] p = new int[N, 11];
            int[] kaburi = new int[N];

            for(int i = 0; i < N; i++)
            {
                string[] str = Console.ReadLine().Split(' ');
                for(int j = 0; j < 10; j++)
                {
                    f[i, j] = int.Parse(str[j]);
                }
            }

            for (int i = 0; i < N; i++)
            {
                string[] str = Console.ReadLine().Split(' ');
                for (int j = 0; j < 11; j++)
                {
                    p[i, j] = int.Parse(str[j]);
                }
            }


            ss = new List<string>();

            Me(0, "");
           
            int max = int.MinValue;
            for(int i = 0; i < ss.Count; i++)
            {
                if (ss[i] == "0000000000") continue;

                for(int j = 0; j < N; j++)
                {
                    kaburi[j] = 0;
                }

                string s = ss[i];
                int sum = 0;
                for(int j = 0; j < s.Length; j++)
                {
                    //k????????????
                    for(int k = 0; k < N; k++)
                    {
                        if (f[k, j] == 1 && s[j] == '1') kaburi[k]++;
                    }                 
                }

                //j??????????
                for(int j = 0; j < N; j++)
                {
                    //Console.WriteLine($"j = {j} kaburi[{j}] = {kaburi[j]}");
                    sum += p[j, kaburi[j]];
                }
                //Console.WriteLine($"{s}?{sum}");
                if (max < sum) max = sum;

            }

            Console.WriteLine(max);
        }
    }
}