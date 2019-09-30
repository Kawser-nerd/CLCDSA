using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace GoogleJam
{
    class Program
    {
        [STAThread]
        static void Main(string[] args)
        {
            StreamReader reader = new StreamReader(@"C:\!Install\Input.txt");
            StreamWriter writer = new StreamWriter(@"C:\!Install\Output.txt");
            int tasks = Int32.Parse(reader.ReadLine());
            for(int t = 0; t < tasks; t++)
            {
                StreamReader preader = new StreamReader(@"C:\!Install\primes.txt"); // one prime number per line, ascending
                string[] tmp = reader.ReadLine().Split(new char[] { ' ' });
                int a = Int32.Parse(tmp[0]);
                int b = Int32.Parse(tmp[1]);
                int p = Int32.Parse(tmp[2]);
                int[] numbers = new int[b - a + 1];
                for (int i = a; i <= b; i++)
                    numbers[i - a] = i;
                int currp = 0;
                while (currp < p)
                    currp = Int32.Parse(preader.ReadLine());
                int skupin = (b - a + 1);
                while (currp <= b)
                {
                    for (int i = a; i < b; i++)
                    {
                        for (int j = a + 1; j <= b; j++)
                        {
                            if (numbers[i - a] == numbers[j - a])
                                continue;
                            if ((i % currp == 0) && (j % currp == 0))
                            {
                                int oldskupina = numbers[j - a];
                                skupin--;
                                for (int k = a; k <= b; k++)
                                {
                                    if (numbers[k - a] == oldskupina)
                                        numbers[k - a] = numbers[i - a];
                                }
                            }
                        }   
                    }
                    currp = Int32.Parse(preader.ReadLine());
                }
                writer.WriteLine(String.Format("Case #{0}: {1}", t + 1, skupin));
                preader.Close();
            }
            reader.Close();
            writer.Close();
        }
    }
}

                //string[] tmp = reader.ReadLine().Split(new char[] { ' ' });
                //int n, A, B, C, D, x0, y0, M;
                //n = Int32.Parse(tmp[0]);
                //A = Int32.Parse(tmp[1]);
                //B = Int32.Parse(tmp[2]);
                //C = Int32.Parse(tmp[3]);
                //D = Int32.Parse(tmp[4]);
                //x0 = Int32.Parse(tmp[5]);
                //y0 = Int32.Parse(tmp[6]);
                //M = Int32.Parse(tmp[7]);
                //int X = x0;
                //int Y = y0;
                //writer.WriteLine(String.Format("{0} {1}", X, Y));
                //for(int i = 0; i < n; i++)
                //{
                //    X = (A * X + B) % M;
                //    Y = (C * Y + D) % M;
                //    writer.WriteLine(String.Format("{0} {1}", X, Y));
                //}

                //break;
