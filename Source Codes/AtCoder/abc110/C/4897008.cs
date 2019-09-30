using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

namespace AtCoderABC086
{
    class Program
    {
        public static void Main(string[] args)
        {
            string S = Console.ReadLine();
            string T = Console.ReadLine();
            bool flag = true;
            Dictionary<char, char> dict =  new Dictionary<char, char>();
            Dictionary<char, char> dict2 =  new Dictionary<char, char>();
            for (int i = 0; i < S.Length; i++)
            {
                if (dict.ContainsKey(S[i]) && dict[S[i]] != T[i])
                {
                    flag = false;
                    break;
                }
                if (dict2.ContainsKey(T[i]) && dict2[T[i]] != S[i])
                {
                    flag = false;
                    break;
                }
                if (!dict.ContainsKey(S[i])) dict[S[i]] = T[i];
                if (!dict2.ContainsKey(T[i])) dict2[T[i]] = S[i];
            }
            Console.WriteLine((flag)? "Yes": "No");
        }
    }
}