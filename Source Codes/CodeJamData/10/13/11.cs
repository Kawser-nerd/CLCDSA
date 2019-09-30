using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace codejam1A2
{
    class Program
    {

        static void Main(string[] args)
        {

            int t;
            int a1, a2, b1, b2;
            string line = string.Empty;

            using (StreamReader sr = new StreamReader(@"C-small-attempt0.in"))
			{

                line = sr.ReadLine();

                t = Int32.Parse(line.Trim());

                for (int l = 1; l <= t; l++)
                {
                    line = sr.ReadLine();
                    string[] terms = line.Split(' ');
                    a1 = Int32.Parse(terms[0].Trim());
                    a2 = Int32.Parse(terms[1].Trim());
                    b1 = Int32.Parse(terms[2].Trim());
                    b2 = Int32.Parse(terms[3].Trim());

                    int count = 0;
                    for (int i = a1; i <= a2; i++)
                    {
                        for (int j = b1; j <= b2; j++)
                        {
                            if (IsWinnerNumber(i, j))
                            {
                                count++;
                            }
                        }
                    }

                    Console.WriteLine("Case #" + l + ": " + count);
                }
			}

		}


        static bool IsWinnerNumber(int a, int b)
        {
            if (a == b)
                return false;
            
            if (a < b)
            {
                int tmp = a;
                a = b;
                b = tmp;
            }
            
            int m = a % b;

            if (m == 0)
                return true;
            
            if (a / b > 1)
            {
                if (!IsWinnerNumber(b, a % b + b))
                    return true;
                if (!IsWinnerNumber(b, a % b))
                    return true;
            }
            else
            {
                if (!IsWinnerNumber(b, a % b))
                    return true;
            }
           
            return false;

        }

    }
}
