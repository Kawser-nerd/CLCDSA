using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

public class Program
{
    public static void Main()
    {

        var N = int.Parse(Console.ReadLine());
        List<int> list = new List<int>();
        List<int> outPut = new List<int>();

        for (int i = 0; i < N; i++)
        {
            var tmp = int.Parse(Console.ReadLine());
            list.Add(tmp);
        }

        outPut.Add(list[0]);
        for (int i = 0; i < N; i++)
         {
            if (outPut.Last() < list[i])
            {
                outPut.Add(list[i]);
            }
            else
            {
                var index = outPut.FindIndex(n => n >= list[i]);
                if (index - 1 < 0)
                {
                    outPut[0] = list[i];
                }
                else
                {
                    outPut[index] = list[i];
                }
            }
        }

        //Console.WriteLine(outPut.Count());

        if (outPut.Count() > 1)
        {
            Console.WriteLine(N - outPut.Count());
        }
        else
        {
            Console.WriteLine(N - 1);
        }
    }
}