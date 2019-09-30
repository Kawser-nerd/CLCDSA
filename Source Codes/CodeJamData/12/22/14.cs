using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace R1BP2
{
    class Program
    {

        private static int[,] mazeFloor;
        private static int[,] mazeCeil;
        private static double[,] bestTimeOut;
        private static int[,] zerroVisit;

        private static int X;
        private static int Y;
        private static int LEV;

        static double  Move(int curentX, int curentY, double curentTime, int[,] visited)
        {
            double ret = double.MaxValue;
            double retUp = double.MaxValue;
            double retDown = double.MaxValue;
            double retLeft = double.MaxValue;
            double retRight = double.MaxValue;


            if (visited[curentX, curentY] == 1)
            {
                return (double.MaxValue);
            }
            int[,] pviZ = new int[X, Y];
            for (int i = 0; i < X; i++)
            {
                for (int c = 0; c < Y; c++)
                {
                    pviZ[i, c] = visited[i, c];
                }
            }
            pviZ[curentX, curentY] = 1;
            
            if ((curentX == (X - 1)) && (curentY == (Y - 1)))
            {
                return (curentTime);
            }


            if ((bestTimeOut[curentX, curentY] <= curentTime)&&(bestTimeOut[curentX, curentY] >=0))
            {
                return (bestTimeOut[curentX, curentY]);
            }

            //Move up

            if (curentY > 0)
            {
                if ((mazeCeil[curentX, curentY - 1]) >= (mazeFloor[curentX, curentY - 1] + 50))
                    if ((mazeCeil[curentX, curentY]) >= (mazeFloor[curentX, curentY - 1] + 50))
                        if ((50 + mazeFloor[curentX, curentY]) <= mazeCeil[curentX, curentY - 1])
                    {
                    double delay = 0;
                    if ((LEV - curentTime * 10 + 50) > mazeCeil[curentX, curentY - 1])
                    {
                        delay = Math.Abs((mazeCeil[curentX, curentY - 1] - 50) - (LEV - curentTime * 10)) / 10;
                    }
                    if ((delay + curentTime) > 0)
                    {
                        if ((mazeFloor[curentX, curentY] + 20) <= (LEV - (delay + curentTime) * 10))
                        {
                            delay += 1;
                        }
                        else
                        {
                            delay += 10;
                        }
                    }

                    if ((bestTimeOut[curentX, curentY] <= (curentTime + delay)) && (bestTimeOut[curentX, curentY] >= 0))
                    {
                    }
                    else
                    {
                        retUp = Move(curentX, curentY - 1, curentTime + delay, pviZ);
                    }
                }
            }


            if (curentX > 0)
            {
                if ((mazeCeil[curentX - 1, curentY]) >= (mazeFloor[curentX - 1, curentY] + 50))
                    if ((mazeCeil[curentX, curentY]) >= (mazeFloor[curentX-1, curentY ] + 50))
                        if ((50 + mazeFloor[curentX, curentY]) <= mazeCeil[curentX-1, curentY ])
                {
                    double delay = 0;
                    if ((LEV - curentTime * 10 + 50) > mazeCeil[curentX - 1, curentY])
                    {
                        delay = Math.Abs((mazeCeil[curentX - 1, curentY] - 50) - (LEV - curentTime * 10)) / 10;
                    }
                    if ((delay + curentTime) > 0)
                    {
                        if ((mazeFloor[curentX, curentY] + 20) <= (LEV - (delay + curentTime) * 10))
                        {
                            delay += 1;
                        }
                        else
                        {
                            delay += 10;
                        }
                    }

                    if ((bestTimeOut[curentX, curentY] <= (curentTime + delay)) && (bestTimeOut[curentX, curentY] >= 0))
                    {
                    }
                    else
                    {
                        retLeft = Move(curentX - 1, curentY, curentTime + delay, pviZ);
                    }
                }
            }













            if (curentY < (Y-1))
            {
                if ((mazeCeil[curentX, curentY + 1]) >= (mazeFloor[curentX, curentY + 1] + 50))
                    if ((mazeCeil[curentX, curentY]) >= (mazeFloor[curentX, curentY + 1]+50))
                        if ((50 + mazeFloor[curentX, curentY]) <= mazeCeil[curentX, curentY + 1])
                        {
                    double delay = 0;
                    if ((LEV - curentTime * 10 + 50) > mazeCeil[curentX, curentY + 1])
                    {
                        delay = Math.Abs((mazeCeil[curentX, curentY + 1] - 50) - (LEV - curentTime * 10)) / 10;
                    }
                    if ((delay + curentTime) > 0)
                    {
                        if ((mazeFloor[curentX, curentY] + 20) <= (LEV - (delay + curentTime) * 10))
                        {
                            delay += 1;
                        }
                        else
                        {
                            delay += 10;
                        }
                    }

                    if ((bestTimeOut[curentX, curentY] <= (curentTime + delay)) && (bestTimeOut[curentX, curentY] >= 0))
                    {
                    }
                    else
                    {
                        retDown = Move(curentX, curentY + 1, curentTime + delay, pviZ);
                    }
                }
            }


            if (curentX < (X-1))
            {
                if ((mazeCeil[curentX + 1, curentY]) >= (mazeFloor[curentX+1, curentY] + 50))
                    if ((mazeCeil[curentX, curentY]) >= (mazeFloor[curentX+1, curentY ] + 50))
                        if ((50 + mazeFloor[curentX, curentY]) <= mazeCeil[curentX+1, curentY ])
                {
                    double delay = 0;
                    if ((LEV - curentTime * 10 + 50) > mazeCeil[curentX + 1, curentY])
                    {
                        delay = Math.Abs((mazeCeil[curentX + 1, curentY] - 50) - (LEV - curentTime * 10)) / 10;
                    }
                    if ((delay + curentTime) > 0)
                    {
                        if ((mazeFloor[curentX, curentY] + 20) <= (LEV - (delay + curentTime) * 10))
                        {
                            delay += 1;
                        }
                        else
                        {
                            delay += 10;
                        }
                    }

                    if ((bestTimeOut[curentX, curentY] <= (curentTime + delay)) && (bestTimeOut[curentX, curentY] >= 0))
                    {
                    }
                    else
                    {
                        retRight = Move(curentX + 1, curentY, curentTime + delay, pviZ);
                    }
                }
            }

            if (retDown < ret)
            {
                ret = retDown;
            }
            if (retLeft < ret)
            {
                ret = retLeft;
            }
            if (retUp < ret)
            {
                ret = retUp;
            }
            if (retRight < ret)
            {
                ret = retRight;
            }

            if ((bestTimeOut[curentX, curentY] <= ret) && (bestTimeOut[curentX, curentY] >= 0))
            {
                return (bestTimeOut[curentX, curentY]);
            }
            else
            {
                bestTimeOut[curentX, curentY] = ret;
                return(ret);
            }
        }

        static void Main(string[] args)
        {
            Console.WriteLine(DateTime.Now);

            String[] input = File.ReadAllText("input.txt").Split('\n');
            String output = "";

            int curent = 1;

            for (int iter = 0; iter < Int32.Parse(input[0]); iter++)
            {
                LEV = Int32.Parse(input[curent].Split(' ')[0]);
                X = Int32.Parse(input[curent].Split(' ')[1]); ;
                Y = Int32.Parse(input[curent].Split(' ')[2]); ;

                curent++;

                zerroVisit = new int[X, Y];
                bestTimeOut = new double[X, Y];
                mazeFloor = new int[X, Y];
                mazeCeil = new int[X, Y];

                for (int i = 0; i < X; i++)
                {
                    for (int c = 0; c < Y; c++)
                    {
                        mazeCeil[i, c] = Int32.Parse(input[curent].Split(' ')[c]);
                    }
                    curent++;
                }
                for (int i = 0; i < X; i++)
                {
                    for (int c = 0; c < Y; c++)
                    {
                        mazeFloor[i, c] = Int32.Parse(input[curent].Split(' ')[c]);
                    }
                    curent++;
                }
                for (int i = 0; i < X; i++)
                {
                    for (int c = 0; c < Y; c++)
                    {
                        bestTimeOut[i, c] = -1;
                    }
                }
                for (int i = 0; i < X; i++)
                {
                    for (int c = 0; c < Y; c++)
                    {
                        zerroVisit[i, c] = -1;
                    }
                }
                int[,] pviZ = new int[X, Y];
                for (int i = 0; i < X; i++)
                {
                    for (int c = 0; c < Y; c++)
                    {
                        pviZ[i, c] = 0;
                    }
                }

                double bestTime = Move(0, 0, 0, pviZ);


                output += "Case #" + (iter+1).ToString() + ": " + bestTime.ToString() + "\n";
                Console.WriteLine("Case #" + iter + ": " + bestTime.ToString());
            }


            File.WriteAllText("output.txt", output.Trim());
            Console.ReadLine();


        }
    }
}
