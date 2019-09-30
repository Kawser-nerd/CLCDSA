using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Atcoder
{
    class AtCodeeeeeeeeeeeeeeeeeeeer
    {
        static void Main(string[] args)
        {
            string A = Console.ReadLine();
            string B = Console.ReadLine();
            string ans = "EQUAL";
            if (A.Length==B.Length)
            {
                for (int i = 0; i < A.Length; i++)
                {
                    int a = A[i];
                    int b = B[i];
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
            else
            {
                if (A.Length > B.Length)
                {
                    ans = "GREATER";
                }
                else if (A.Length <B.Length)
                {
                    ans = "LESS";
                }
            }
            Console.WriteLine(ans);
        }
    }
}