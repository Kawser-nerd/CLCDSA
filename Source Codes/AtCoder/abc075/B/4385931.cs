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
            int[] s = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int H = s[0];
            int W = s[1];
            char[,] glid = new char[H, W];
            //8?????
            int[] xi = { 1, 1, 1, 0, -1, -1, -1, 0 };
            int[] yi = { 1, 0, -1, -1, -1, 0, 1, 1 };
            for (int i = 0; i < H; i++)
            {
                string str = Console.ReadLine();
                for (int j = 0; j < W; j++)
                {
                    glid[i, j] = str[j];
                }
            }


            for (int h = 0; h < H; h++)
            {
                for (int w = 0; w < W; w++)
                {
                    if (glid[h,w]!='#')
                    {
                        int ans = 0;
                        for (int i = 0; i < 8; i++)
                        {
                            int Hnext = h + xi[i];
                            int Wnext = w + yi[i];
                            if (H > Hnext && Hnext >= 0 && W > Wnext && Wnext >= 0)
                            {
                                if (glid[Hnext, Wnext] == '#')
                                {
                                    ans++;
                                }
                            }
                            
                        }
                        glid[h, w] = char.Parse(ans.ToString());
                    }
                }
            }

            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    Console.Write(glid[i, j]);
                }
                Console.Write("\n");
            }
        }
    }
}