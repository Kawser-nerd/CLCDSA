using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder.ABC114
{
    public class B
    {
        public static void Solve()
        {
            string[] input = Console.ReadLine().Split(' ');
            string s1 = input[0];
            
            //?int arr[s.len -2]
            var numList = new List<int>();

            //for int i = 0 ; i <= s.len -2 ; i++ 
            // X = S[i..j] ; i=0 ; j+=2;
            //List<int>.GetRange(i,j); ??
            // Stringj.Substring???
            // int parse(X)
            for (int i = 0 ; i < s1.Length - 2; i++)
            {
                var num = s1.Substring(i,3);
                int n = Math.Abs(753 - int.Parse(num));
                numList.Add(n);
            }

            // xs = | 753 - X | * (S.len -2)
            // min(xs)
            Console.WriteLine(numList.Min());
        }    
    }
}

namespace AtCoder {
    class Program
    {
        static void Main(string[] args)
        {
            ABC114.B.Solve();
        }
    }
}