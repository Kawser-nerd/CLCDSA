using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        var line = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);

        int N = line[0];
        int[] pre = new int[]{ 1,2,3,4,5,6};
        //int K = line[1];


        //double[] db = new double[] { };
        //db = Array.ConvertAll(Console.ReadLine().Split(), double.Parse);
        //Array.Sort(db);

        //double cur = 0;
        //double tmp = 0;

        //for (int i = N-K; i < N; i++)
        //{
        //    cur = (db[i] + cur) / 2;
        //}
        //Console.WriteLine(cur);

        if (true)
        {
            N = N % 30;
        }

        int index1 = 0;
        int index2 = 0;
        int tmp = 0;


        for (int i = 0; i < N; i++)
        {
            index1 = (i % 5);
            index2 = (i % 5) + 1;

            tmp = pre[index1];
            pre[index1] = pre[index2];
            pre[index2] = tmp;
        }

        for (int i = 0; i < 6; i++)
        {
            if (i != 5)
            {
                Console.Write(pre[i]);
            }
            else
            {
                Console.WriteLine(pre[i]);
            }
            
        }
    }
}