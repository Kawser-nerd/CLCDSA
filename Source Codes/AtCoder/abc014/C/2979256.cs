using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace AtTest.C_Challenge
{
    class ABC_014
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            var questions = new int[n, 2];
            for (int i = 0; i < n; i++)
            {
                string[] input = Console.ReadLine().Split(' ');
                questions[i, 0] = int.Parse(input[0]);
                questions[i, 1] = int.Parse(input[1]);
            }
            
            var likes = new int[1000001];
            for(int i = 0; i < n; i++)
            {
                likes[questions[i, 0]]++;
                if (questions[i, 1] < likes.Length - 1)
                {
                    likes[questions[i, 1] + 1]--;
                }
            }
            for(int i = 1; i < likes.Length; i++)
            {
                likes[i] += likes[i - 1];
            }
            Console.WriteLine(likes.Max());
        }
    }
}