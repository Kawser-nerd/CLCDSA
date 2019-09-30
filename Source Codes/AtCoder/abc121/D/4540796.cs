using System;
using System.Collections.Generic;
using System.Linq;

namespace CSharpSample01
{

    
    class Program
    {

        static int[] Two_from_Ten(long a)
        {
            int[] ans_two = new int[50];

            long b = 0;

            int cnt = 0;
            while (true)
            {
                b = a % 2;
                a /= 2;

                ans_two[cnt] = (int)b;

                if(a == 0)
                {
                    break;
                }
                cnt++;
            }

            for(int i = cnt + 1; i < ans_two.Length; i++)
            {
                ans_two[i] = 0;
            }

            return ans_two;
        }

        static long Ten_from_Two(int[] nisin)
        {
            long ans_ten = 0;

            int cnt_sisu = 0;
            for(int i = 0; i < nisin.Length; i++)
            {               
                if(nisin[i] == 1)
                {
                    ans_ten += (long)Math.Pow(2, cnt_sisu);
                }
                cnt_sisu++;
            }

            return ans_ten;
        }

        static int[] XOR_by_two(int[] a, int[] b)
        {
            int[] s = new int[a.Length];
            
            for(int i = 0; i < a.Length; i++)
            {
                if(a[i] != b[i])
                {
                    s[i] = 1;
                }
                else
                {
                    s[i] = 0;
                }
            }

            return s;
        }

        static long Solve(long A)
        {
            long ans_ten = 0;
            long cnt_one;
            if(A % 2 == 1)
            {
                cnt_one = (A + 1) / 2;
                
                if(cnt_one % 2 == 1)
                {
                    ans_ten = 0;
                }
                else
                {
                    ans_ten = 1;
                }
            }
            else
            {
                cnt_one = A / 2;
                int B = 0;

                if(cnt_one % 2 == 1)
                {
                    B = 0;
                }
                else
                {
                    B = 1;
                }

                int[] left_two = Two_from_Ten(B);
                int[] right_two = Two_from_Ten(A);

                ans_ten = Ten_from_Two(XOR_by_two(left_two, right_two));

            }

            return ans_ten;
        }


        static void Main(string[] args)
        {
            string[] str = Console.ReadLine().Split(' ');
            long A = long.Parse(str[0]);
            long B = long.Parse(str[1]);

            long a_ten = Solve(A - 1);
            long b_ten = Solve(B);

            /*
            Console.WriteLine("a : " + a_ten);
            Console.WriteLine("b : " + b_ten);
            */

            long ans_ten = Ten_from_Two(XOR_by_two(Two_from_Ten(a_ten), Two_from_Ten(b_ten)));

            Console.WriteLine(ans_ten);
            
        }
    }
}