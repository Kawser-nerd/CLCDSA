using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace CodeJam14
{
    class Program
    {
        static void Main(string[] args)
        {
            File_Manager.Open(@"C:\Users\Plumley\Downloads\A-large (2).in");

            //Problem call goes here
            Part_Elf();

            File_Manager.Close();
            File_Manager.Write(@"C:\Users\Plumley\Downloads\A-large (2).out");
            System.Console.WriteLine("Done");
            System.Console.ReadLine(); //Pause
        }

        static void Magic_Trick()
        {
            int T = File_Manager.ReadInts()[0];
            for (int t = 0; t < T; t++)
            {
                int ans1 = File_Manager.ReadInts()[0];
                List<int> row1 = new List<int>();
                for (int r = 1; r < 5; r++)
                {
                    if (r == ans1)
                        row1 = File_Manager.ReadInts();
                    else
                        File_Manager.ReadLine();
                }

                int ans2 = File_Manager.ReadInts()[0];
                List<int> row2 = new List<int>();
                for (int r = 1; r < 5; r++)
                {
                    if (r == ans2)
                        row2 = File_Manager.ReadInts();
                    else
                        File_Manager.ReadLine();
                }

                List<int> values = new List<int>();
                foreach (int a in row1)
                {
                    if (row2.Contains(a))
                        values.Add(a);
                }
                if (values.Count == 0)
                    File_Manager.QueueLine("Case #" + (t + 1).ToString() + ": " + "Volunteer cheated!");
                else if (values.Count == 1)
                    File_Manager.QueueLine("Case #" + (t + 1).ToString() + ": " + values[0]);
                else
                    File_Manager.QueueLine("Case #" + (t + 1).ToString() + ": " + "Bad magician!");
            }
        }

        static void Cookie_Clicker_Alpha()
        {
            int T = File_Manager.ReadInts()[0];
            for (int t = 0; t < T; t++)
            {
                List<double> CFX = File_Manager.ReadDoubles();
                double C = CFX[0];
                double F = CFX[1];
                double X = CFX[2];
                double rate = 2;
                double time = 0;

                while(true)
                {
                    if ((X / (rate + F)) >= ((X - C) / rate))
                    {
                        time += X / rate;
                        break;
                    }
                    else
                    {
                        time += C / rate;
                        rate += F;
                    }
                }

                File_Manager.QueueLine("Case #" + (t + 1).ToString() + ": " + time.ToString("0.0000000"));
            }
        }

        static void Deceitful_War()
        {
            int T = File_Manager.ReadInts()[0];
            for (int t = 0; t < T; t++)
            {
                int N = File_Manager.ReadInts()[0];
                List<double> Naomi = File_Manager.ReadDoubles();
                List<double> Ken = File_Manager.ReadDoubles();
                Naomi.Sort();
                Ken.Sort();
                List<double> NW = new List<double>(Naomi);
                List<double> KW = new List<double>(Ken);

                int NWScore = 0;
                for (int n = N - 1; n >= 0; n--)
                {
                    if (NW[n] > KW[n])
                    {
                        NWScore++;
                        NW.RemoveAt(n);
                        KW.RemoveAt(0);
                    }
                    else
                    {
                        NW.RemoveAt(n);
                        KW.RemoveAt(n);
                    }
                }

                int NDWScore = 0;
                for (int n = N - 1; n >= 0; n--)
                {
                    if (Naomi[0] > Ken[0])
                    {
                        NDWScore++;
                        Naomi.RemoveAt(0);
                        Ken.RemoveAt(0);
                    }
                    else
                    {
                        Naomi.RemoveAt(0);
                        Ken.RemoveAt(n);
                    }
                }

                File_Manager.QueueLine("Case #" + (t + 1).ToString() + ": " + NDWScore + " " + NWScore);
            }
        }

        static void Minesweeper_Master()
        {

        }

        static void The_Repeater()
        {
            int T = File_Manager.ReadInts()[0];
            for (int t = 0; t < T; t++)
            {
                bool fail = false;
                int N = File_Manager.ReadInts()[0];
                string[] strings = new string[N];
                List<char> order = new List<char>();
                List<int[]> counts = new List<int[]>();
                for (int n = 0; n < N; n++)
                {
                    strings[n] = File_Manager.ReadLine();
                    char[] letters = strings[n].ToCharArray();
                    if (n == 0)
                    {
                        order.Add(letters[0]);
                        counts.Add(new int[N]);
                    }
                    int orderNo = 0;
                    for (int i = 0; i < letters.Length; i++)
                    {
                        if (letters[i] == order[orderNo])
                        {
                            counts[orderNo][n]++;
                        }
                        else
                        {
                            if (order.Count > orderNo + 1)
                            {
                                if (order[orderNo + 1] == letters[i])
                                {
                                    orderNo++;
                                    counts[orderNo][n] = 1;
                                }
                                else
                                {
                                    fail = true;
                                }
                            }
                            else
                            {
                                orderNo++;
                                order.Add(letters[i]);
                                counts.Add(new int[N]);
                                counts[orderNo][n] = 1;
                            }
                        }
                    }
                }
                int noChars = order.Count;
                int moves = 0;
                for (int i = 0; i < noChars; i++)
                {
                    if (counts[i].Contains(0))
                    {
                        fail = true;
                    }
                    else
                    {
                        Array.Sort(counts[i]);
                        for (int a = 0; a < N; a++)
                        {
                            moves += Math.Abs(counts[i][a] - counts[i][(int)(N / 2)]);
                        }
                    }
                }
                if (fail)
                {
                    File_Manager.QueueLine("Case #" + (t + 1).ToString() + ": " + "Fegla Won");
                }
                else
                {
                    File_Manager.QueueLine("Case #" + (t + 1).ToString() + ": " + moves);
                }
                
            }

        }

        static void The_Bored_Traveling_Salesman()
        {
            //start at lowest
             //   consider children of all chosen
              //      pick lowest unless not picking a current child
               //         then pick lowest who can reach current children
            
            int T = File_Manager.ReadInts()[0];
            for (int t = 0; t < T; t++)
            {
                List<int> NM = File_Manager.ReadInts();
                int N = NM[0];
                int M = NM[1];
                int[] zips = new int[N];
                int[][] cons = new int[N][];
                for (int n = 0; n < N; n++)
                {
                    zips[n] = File_Manager.ReadInts()[0];
                    cons[n] = new int[N];
                }
                for (int m = 0; m < M; m++)
                {
                    List<int> ab = File_Manager.ReadInts();
                    cons[ab[0]][ab[1]] = 1;
                    cons[ab[1]][ab[0]] = 1;
                }

                List<int> order = new List<int>();
                order.Add(Array.IndexOf(zips, zips.Min()));
                int curZip = zips.Min();
                List<int> front = new List<int>();
                for (int i = 0; i < N; i++)
                {
                }

                    File_Manager.QueueLine("Case #" + (t + 1).ToString() + ": ");
            }
        }

        static void Part_Elf()
        {
            int T = File_Manager.ReadInts()[0];
            for (int t = 0; t < T; t++)
            {
                BigInteger[] AB = File_Manager.ReadBigInts().ToArray();
                double frac = (double)((double)AB[0] / (double)AB[1]);
                string bin = DoubleToBinary(frac, 41);
                Simplify(AB);
                if (AB[1].IsPowerOfTwo && bin.Contains('1'))
                {
                    int n = bin.IndexOf('1') - 1;
                    File_Manager.QueueLine("Case #" + (t + 1).ToString() + ": " + n);
                }
                else
                {
                    File_Manager.QueueLine("Case #" + (t + 1).ToString() + ": " + "impossible");
                }
            }
        }
        static void Simplify(BigInteger[] numbers)
        {
            BigInteger gcd = GCD(numbers);
            for (int i = 0; i < numbers.Length; i++)
                numbers[i] /= gcd;
        }
        static BigInteger GCD(BigInteger a, BigInteger b)
        {
            while (b > 0)
            {
                BigInteger rem = a % b;
                a = b;
                b = rem;
            }
            return a;
        }
        static BigInteger GCD(BigInteger[] args)
        {
            // using LINQ:
            return args.Aggregate((gcd, arg) => GCD(gcd, arg));
        }

        static String DoubleToBinary(Double base10, Int32 decimalPlaces)
        {
            // divided by 2 (because binary)
            Double divisor = 1.0 / 2.0;

            // this will hold the output
            String binary = "0.";

            for (Int32 i = 0; i < decimalPlaces; i++)
            {
                if (base10 >= divisor)
                {
                    binary += '1';
                    base10 -= divisor;
                }
                else
                    binary += '0';

                // divide by 2 (because binary)
                divisor /= 2.0;
            }

            // trim the insignificant zero's
            return binary.TrimEnd('0');
        }
    }
}
