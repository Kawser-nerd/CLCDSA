using System;
using System.Collections.Generic;

namespace CompetitiveProgramming
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            var charList = new List<char>();
            foreach(char c in s)
            {
                charList.Add(c);
            }
            int min = 1000;

            for (var i = 0; i < charList.Count - 2;i++)
            {
                int first = int.Parse(charList[i].ToString());
                int second = int.Parse(charList[i+1].ToString());
                int third = int.Parse(charList[i+2].ToString());
                int number = first * 100 + second * 10 + third;
                int ans = Math.Abs(number - 753);
                if (ans < min)
                {
                    min = ans;
                }
            }
            Console.WriteLine(min);
        }

    }
}