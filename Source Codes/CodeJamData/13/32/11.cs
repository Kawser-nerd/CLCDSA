using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;


namespace ConsoleApplication1
{
    class Class2
    {
        StreamReader sr;
        StreamWriter sw;

        public Class2(string infile, string outfile)
        {
            sr = new StreamReader(infile);
            sw = new StreamWriter(outfile);
        }
        /*
         Sample Input:
         * 
         2
         3 4
         -3 4
         */

        public void Execute()
        {
            Int64 NumCases = Int64.Parse(sr.ReadLine());
            for (Int64 k = 0; k < NumCases; k++)
            {
                string outputString = "";
                string line = sr.ReadLine();

                Int64 x = Int64.Parse(line.Split(' ')[0]);
                Int64 y = Int64.Parse(line.Split(' ')[1]);

                Int64 currentX = 0;
                Int64 currentY = 0;

                //not sure how to do the optimal path
                //for the reasonable path, we just need to pick the largest directional gap, then go that direction.  If that gap is smaller than our jump size, we go in the opposite direction
                //we can move 1 space in any direction by taking two jumps (away then back)
                //we can move 2x2 in any direction1 by direction2 by taking 4 jumps (direction3, direction4, direction1, direction2).  We do this whenever we're more than 1x1 away from target and our jump size > 2
                for (int i = 1; (x != currentX || y != currentY); i++)
                {
                    //i is our jump size
                    Int64 xGap =  x - currentX;
                    Int64 yGap = y - currentY;
                    string jumpString = "";

                    //special case 2x2 move
                    if (Math.Abs(xGap) / 2 > i && Math.Abs(yGap) / 2 > i && i > 2)
                    {
                        if (xGap > 0)
                        {
                            if (yGap > 0)
                            {
                                jumpString += "SWNE";
                                currentX += 2;
                                currentY += 2;
                                i+= 3;
                            }
                            else
                            {
                                jumpString += "NWSE";
                                currentX += 2;
                                currentY -= 2;
                                i += 3;
                            }
                        }
                        else
                        {
                            if (yGap > 0)
                            {
                                jumpString += "SENW";
                                currentX -= 2;
                                currentY += 2;
                                i += 3;
                            }
                            else
                            {
                                jumpString += "NESW";
                                currentX -= 2;
                                currentY -= 2;
                                i += 3;
                            }
                        }
                    }
                    else if (Math.Abs(xGap) > Math.Abs(yGap))
                    {
                        //x differential is bigger
                        if (Math.Abs(xGap) < i)
                        {
                            //if we jump towards x, we're going to overshoot.  Jump away, then next time we'll jump back
                            if (xGap > 0)
                            {
                                jumpString += "W";
                                currentX -= i;
                            }
                            else
                            {
                                jumpString += "E";
                                currentX += i;
                            }
                        }
                        else
                        {
                            if (xGap > 0)
                            {
                                jumpString += "E";
                                currentX += i;
                            }
                            else
                            {
                                jumpString += "W";
                                currentX -= i;
                            }
                        }
                    }
                    else 
                    {
                        //y diferential is bigger
                        if (Math.Abs(yGap) < i)
                        {
                            //if we jump towards y, we're going to overshoot.  Jump away, then next time we'll jump back
                            if (yGap > 0)
                            {
                                jumpString += "S";
                                currentY -= i;
                            }
                            else
                            {
                                jumpString += "N";
                                currentY += i;
                            }
                        }
                        else
                        {
                            if (yGap > 0)
                            {
                                jumpString += "N";
                                currentY += i;
                            }
                            else
                            {
                                jumpString += "S";
                                currentY -= i;
                            }
                        }
                    }
                    outputString += jumpString;
                    Console.WriteLine(String.Format("currentX = {0}, currentY = {1}, i = {2}, outputstring = {3}", currentX, currentY, i, outputString));
                }
                
                
                sw.WriteLine(String.Format("Case #{0}: {1}", k + 1, outputString));
            }


            sw.Close();
            sr.Close();
        }
    }
}
