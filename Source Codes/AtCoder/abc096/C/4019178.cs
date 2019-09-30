using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC_C
{
    class C096
    {
        static void Main(string[] args)
        {
            string[] a0 = Console.ReadLine().Split(' ');
            int H = int.Parse(a0[0]), W = int.Parse(a0[1]);
            char[,] s = new char[H+2, W+2];
            for (int i = 0; i < H; i++)
            {
                string s1 = Console.ReadLine();
                for (int j = 0; j < W; j++)
                {
                    s[i+1, j+1] = s1[j];
                }
            }

            bool impossible = false;
            for(int i = 1; i <= H; i++)
            {
                for(int j = 1; j <= W; j++)
                {
                    if (s[i, j] == '#')
                    {
                        if(s[i-1,j]!='#' && s[i+1,j]!='#')
                        {
                            if (s[i, j-1] != '#' && s[i, j+1] != '#')
                            {
                                impossible = true;
                                break;
                            }
                        }
                    }
                }
            }

            string r = impossible ? "No" : "Yes";
            Console.WriteLine(r);

        }

        }
    }