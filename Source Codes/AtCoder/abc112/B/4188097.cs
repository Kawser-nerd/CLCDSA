using System;
using System.Collections.Generic;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int N = int.Parse(input[0]);
            int T = int.Parse(input[1]);
            int Answer = 0;

            List<int> ListCost= new List<int>();
            List<int> ListTime = new List<int>();

            for (int i = 0; i < N; i++)
            {
                string[] CostTime = Console.ReadLine().Split(' ');
                ListCost.Add(int.Parse(CostTime[0]));
                ListTime.Add(int.Parse(CostTime[1]));

                if (ListTime[i] <= T)
                {
                    if (Answer==0)
                    {
                        Answer = ListCost[i];
                    }else if (ListCost[i] < Answer)
                    {
                        Answer = ListCost[i];
                    }
                }

                if (i==N-1)
                {
                    if (Answer==0)
                    {
                        Console.WriteLine("TLE");
                    }
                    else
                    {
                        Console.WriteLine(Answer);
                    }
                }

            }
        }
    }
}