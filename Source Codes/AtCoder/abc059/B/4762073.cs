using System;
using System.Linq;
using System.Collections.Generic;
using static System.Math;
using static System.Console;

namespace AtCoder
{
    class AtCoderrrrrr
    {
        static void Main(string[] args)
        {
            string A = ReadLine();
            string B = ReadLine();
            string ans = "EQUAL";
            if (A.Length>B.Length)
            {
                ans = "GREATER";
            }
            else if (A.Length<B.Length)
            {
                ans = "LESS";
            }
            else
            {
                //????
                for (int i = 0; i < A.Length; i++)
                {
                    int a = int.Parse(A[i].ToString());
                    int b = int.Parse(B[i].ToString());
                    if (a>b)
                    {
                        ans = "GREATER";
                        break;
                    }
                    else if (a<b)
                    {
                        ans = "LESS";
                        break;
                    }                    
                }
            }
            WriteLine(ans);
        }
    }
}