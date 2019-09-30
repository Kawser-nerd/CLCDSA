using System;
using System.Linq;
    class Program
    {
        static void Main(string[] args)
        {
            var S = Console.ReadLine().ToCharArray();
            var answer = string.Empty;

            foreach(var item in S)
            {
                if(item=='B')
                {
                    if (!answer.Any()) continue;
                    answer = answer.Remove(answer.Length - 1);
                    continue;
                }
                answer += item;
            }
            Console.WriteLine(answer);
        }
    }