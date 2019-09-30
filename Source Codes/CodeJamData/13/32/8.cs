using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problem_B
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 1)
            {
                throw new NotSupportedException();
            }
            else
            {
                // read file
                string file = args[0];
                string outFile = file.Split('.')[0] + ".out";
                StreamReader stream = new StreamReader(@file);
                StreamWriter outStream = new StreamWriter(new FileStream(@outFile, FileMode.Create))
                {
                    AutoFlush = true
                };

                int testcases = Int32.Parse(stream.ReadLine());
                for (int i = 0; i < testcases; i++)
                {
                    string input = stream.ReadLine();
                    long x = Int64.Parse(input.Split(' ')[0]);
                    long y = Int64.Parse(input.Split(' ')[1]);

                    string solution = solutionMethod(x, y);
                    outStream.Write("Case #" + (i + 1) + ": ");
                    outStream.WriteLine(solution);
                }
            }
        }

        private static string solutionMethod(long x, long y)
        {
            string result = "";
            long approxJumps = (long)Math.Ceiling(-0.5 + Math.Sqrt(2 * (Math.Abs(x) + Math.Abs(y)) + 0.25));
            Boolean success = false;

            while (!success)
            {
                long posX = x;
                long posY = y;
                result = "";

                for (long i = approxJumps; i  >= 1; i--)
                {
                    if (Math.Abs(posX) >= Math.Abs(posY))
                    {
                        if (posX >= 0)
                        {
                            posX -= i;
                            result = result.Insert(0, "E");
                        }
                        else
                        {
                            posX += i;
                            result = result.Insert(0, "W");
                        }
                    }
                    else
                    {
                        if (posY >= 0)
                        {
                            posY -= i;
                            result = result.Insert(0, "N");
                        }
                        else
                        {
                            posY += i;
                            result = result.Insert(0, "S");
                        }
                    }
                }
                if (posX == 0 && posY == 0)
                {
                    success = true;
                }
                else
                {
                    approxJumps++;
                }
            }

            // res struing für negative zahlen umkehren
            return result;
        }


        private static string doubleToString(double d)
        {
            return String.Format("{0:0.000000000000}", d).Replace(',', '.');
        }
    }
}
