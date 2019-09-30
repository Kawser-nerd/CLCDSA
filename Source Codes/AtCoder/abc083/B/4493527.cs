using System;
using System.Collections.Generic;

namespace atcoder
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int N = int.Parse(input[0]);
            int A = int.Parse(input[1]);
            int B = int.Parse(input[2]);
            int sum = 0;

            for(int i=1;i<=N;i++){
                string str = i.ToString();
                char[] chars = str.ToCharArray();
                int SOD = 0;
                foreach(char c in chars){
                    SOD += int.Parse(c.ToString());
                }
                if(SOD >= A && SOD <= B){// A < SOD < B
                    sum += i;
                }
            }
            Console.WriteLine(sum);
        }
    }
}