using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Problem1
{
    class Program
    {
        static bool check(int a, int b)
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
                if (!check(b, a % b + b))
                    return true;
                if (!check(b, a % b))
                    return true;
            }
            else
            {
                if (!check(b, a % b))
                    return true;
            }
           
            /*int count = 1;
            while (m != 0)
            {
                if (a / b > 1)
                {
                    a = a % b + b;
                }
                else
                {
                    a = a % b;
                }
                count++;
                if (a < b)
                {
                    int tmp = a;
                    a = b;
                    b = tmp;
                }
                m = a % b;
                if (m == 0)
                {
                    if (count % 2 == 1)
                        return true;
                    else return false;
                }
            }
            if (count % 2 == 1)
                return true;
            else*/
            return false;

        }

        static void Main(string[] args)
        {
            int t;
            int a1, a2, b1, b2;
            StreamReader sr = new StreamReader(@"C-small-attempt2.in");
            StreamWriter sw = new StreamWriter(@"Out_large.txt");

            string line = sr.ReadLine();

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
                        if (check(i, j))
                        {
                            //Console.WriteLine(String.Format("{0} {1}", i, j));
                            count++;
                        }
                    }
                }

                //Console.WriteLine(count);
                sw.WriteLine("Case #" + l + ": " + count);
            }

            sw.Close();

        }
    }
}
