using System;
using System.Collections.Generic;
using System.Linq;

    class Program
    {
        static void Main(string[] args)
        {
            var S = Console.ReadLine().ToCharArray();
            var T = Console.ReadLine();

            var answer = new List<string>();
            for(int i=0;i<S.Length;i++)
            {
                var tmpS = S.ToList().ToArray();
                for(int k =0;k<T.Length && i+k<S.Length;k++)
                {
                    if (tmpS[i + k] == '?') tmpS[i + k] = T[k];
                    if (tmpS[i + k] != T[k]) break;
                }
                if(string.Concat(tmpS).Contains(T))
                {
                    answer.Add(string.Concat(tmpS).Replace('?', 'a'));
                }
            }

            if(!answer.Any())
            {
                Console.WriteLine("UNRESTORABLE");
                return;
            }
            answer.Sort();
            Console.WriteLine(answer.First());
        }
    }