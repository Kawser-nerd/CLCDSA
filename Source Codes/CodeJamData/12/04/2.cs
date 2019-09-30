using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            string filename = "D-large";
            //string filename = "D-small-attempt0";
            //string filename = "test";

            string[] inLine = File.ReadAllLines(filename + ".in");
            int T = Convert.ToInt32(inLine[0]);
            string[] outLine = new String[T];
            int nextline = 1;

            for (int t = 1; t <= T; t++)
            {
                int result = 0;
                string[] tmp = inLine[nextline++].Split(' ');
                int H = Convert.ToInt32(tmp[0]);
                int W = Convert.ToInt32(tmp[1]);
                int D = Convert.ToInt32(tmp[2]);
                string[] map = new string[H];
                int hX = 0;
                int wX = 0;

                for(int h=0;h<H;h++){
                    map[h] = inLine[nextline++];
                    if (map[h].IndexOf('X') >= 0)
                    {
                        hX = h;
                        wX = map[h].IndexOf('X');
                    }
                }


                for (int a = -1*D; a <= D; a++)
                {
                    for (int b = -1*D; b <= D; b++)
                    {
                        if (!isPrime(Math.Abs(a),Math.Abs( b))) continue;
                        int lcm = 2 * Math.Abs(a * b);
                        if (lcm == 0) lcm = 2;
                        // each step, light travels (a/(2lcm), b/(2lcm))
                        int S = (int) (D * lcm / Math.Pow(Math.Pow(a, 2) + Math.Pow(b, 2), 0.5));
                        int x0 = lcm * hX + lcm/2;
                        int y0 = lcm * wX + lcm/2;

                        int x = x0;
                        int y = y0;
                        int vx = a;
                        int vy = b;

                        Boolean returned = false;

                        for(int s=0;s<S;s++){

                            //Console.WriteLine(x.ToString() + ", " + y.ToString() + ", " + vx.ToString() + ", " + vy.ToString());

                            x += vx;
                            y += vy;
                            if (x == x0 && y == y0)
                            {
                                returned = true;
                                break;
                            }

                            int h = x / lcm;
                            int w = y / lcm;

                            if (x % lcm == 0)
                            {
                                if (y % lcm == 0)
                                {
                                    if (map[h + (vx > 0 ? 0 : -1)][w + (vy > 0 ? 0 : -1)] == '#')
                                    {
                                        if (map[h + (vx < 0 ? 0 : -1)][w + (vy > 0 ? 0 : -1)] == '#')
                                        {
                                            if (map[h + (vx > 0 ? 0 : -1)][w + (vy < 0 ? 0 : -1)] == '#')
                                            {
                                                vx = -vx;
                                                vy = -vy;
                                            }
                                            else
                                            {
                                                vy = -vy;
                                            }
                                        }
                                        else
                                        {
                                            if (map[h + (vx > 0 ? 0 : -1)][w + (vy < 0 ? 0 : -1)] == '#')
                                            {

                                                vx = -vx;
                                            }
                                            else
                                            {
                                                returned = false;
                                                break;
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    if( map[h + (vx > 0 ? 0 : -1)][w] == '#'){
                                         vx = -vx;
                                    }


                                }
                            }
                            else
                            {
                                if (y % lcm == 0)
                                {

                                    if (map[h][w + (vy > 0 ? 0 : -1)] == '#')
                                    {
                                        vy = -vy;
                                    }

                                }
                            }
                        }
                        if (returned) result++;
                    }
                }





                Console.WriteLine("Case #" + t.ToString() + ": " + result.ToString());
                outLine[t - 1] = "Case #" + t.ToString() + ": " + result.ToString();
            }

            File.WriteAllLines(filename + ".out", outLine);

        }

        static private Boolean isPrime(int a, int b)
        {
            if (a == 0 && b == 0) return false;
            if (a == 0 && b == 1) return true;
            if (a == 0 && b > 1) return false;
            if (a == 1 && b == 0) return true;
            if (a > 1 && b == 0) return false;
 
            if(a > b) return isPrime(b, a);
            // a <= b
            if(a == 1) return true;
            if (b % a == 0)
            {
                return false;
            }else{
                return isPrime(b % a, a);
            }

        }
    }
}
