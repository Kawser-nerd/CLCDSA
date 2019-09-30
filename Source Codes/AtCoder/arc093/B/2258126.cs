using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace atcoder
{
    class Program
    {
        static void Main(string[] args)
        {
            var AB = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();

            var A = AB[0];
            var B = AB[1];
            var H = 0;
            var W = 100;

            StringBuilder s = new StringBuilder();

            bool temp = true;
            
            A--;

            while (B >= 2 || temp)
            {
                temp = false;

                for (int i = 0; i < 100; i++)
                {
                    s.Append(".");
                }
                s.Append("\n"); H++;

                for (int i = 0; i < 50; i++)
                {
                    if (B >= 2)
                    {
                        s.Append("#.");
                        B--;
                    }
                    else
                    {
                        s.Append("..");
                    }
                }
                s.Append("\n"); H++;
            }

            for (int i = 0; i < 100; i++)
            {
                s.Append(".");
            }
            s.Append("\n"); H++;

            temp = true;

            while (A >= 1 || temp)
            {
                temp = false;

                B--;

                for (int i = 0; i < 100; i++)
                {
                    s.Append("#");
                }
                s.Append("\n"); H++;

                for (int i = 0; i < 50; i++)
                {
                    if (A >= 1)
                    {
                        s.Append(".#");
                        A--;
                    }
                    else
                    {
                        s.Append("##");
                    }
                }
                s.Append("\n"); H++;
            }

            Console.Write(H + " " + W + "\n");
            Console.Write(s.ToString());
        }
    }
}