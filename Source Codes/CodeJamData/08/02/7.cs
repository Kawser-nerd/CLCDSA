using System;
using System.Collections.Generic;
using System.Text;

namespace TrainTimetable
{
    class Program
    {
        static void Main(string[] args)
        {
            char[] delemet = { ' ', ':' };
            string input;
            int N,T,NA,NB;
            short[] A_arrive = new short[60 * 25];
            short[] A_depart = new short[60 * 25];
            short[] B_arrive = new short[60 * 25];
            short[] B_depart = new short[60 * 25];
            for (int i = 0; i < 60 * 25; i++)
            {
                A_arrive[i] = 0;
                A_depart[i] = 0;
                B_arrive[i] = 0;
                B_depart[i] = 0;
            }
            input = Console.ReadLine();
            N = int.Parse(input);
            for (int n = 0; n < N; n++)
            {
                input = Console.ReadLine();
                T = int.Parse(input);
                input = Console.ReadLine();
                string[] tokens = input.Split(delemet);
                NA = int.Parse(tokens[0]);
                NB = int.Parse(tokens[1]);
                
                for (int a = 0; a < NA; a++)
                {
                    input = Console.ReadLine();
                    tokens = input.Split(delemet);
                    A_depart[int.Parse(tokens[0])*60+int.Parse(tokens[1])]++;
                    B_arrive[int.Parse(tokens[2]) * 60 + int.Parse(tokens[3])+T]++;
                }
                for (int b = 0; b < NB; b++)
                {
                    input = Console.ReadLine();
                    tokens = input.Split(delemet);
                    B_depart[int.Parse(tokens[0])*60+int.Parse(tokens[1])]++;
                    A_arrive[int.Parse(tokens[2])*60+int.Parse(tokens[3])+T]++;
                }
                int ans1 = 0;
                int ans2 = 0;
                int x = 0;
                int y = 0;
                for (int i = 0; i < 60 * 24; i++)
                {
                    x -= A_arrive[i];
                    x += A_depart[i];
                    if (ans1 < x)
                        ans1 = x;
                    y -= B_arrive[i];
                    y += B_depart[i];
                    if (ans2 < y)
                        ans2 = y;
                    A_arrive[i] = 0;
                    A_depart[i] = 0;
                    B_arrive[i] = 0;
                    B_depart[i] = 0;
                }
                for (int i = 0; i < 60; i++)
                {
                    A_arrive[i + 60 * 24] = 0;
                    A_depart[i + 60 * 24] = 0;
                    B_arrive[i + 60 * 24] = 0;
                    B_depart[i + 60 * 24] = 0;
                }
                int temp = n + 1;
                Console.WriteLine("Case #" + temp.ToString() + ": " +ans1.ToString() +  " "+ans2.ToString());
            }
        }
    }
}
