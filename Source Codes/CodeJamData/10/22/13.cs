using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace _2010CJR0
{
    class R1P2
    {
        static void Main(string[] args)
        {
            String fileData = File.ReadAllText("c:\\DataR1_1_T.txt");
            String[] temp = fileData.Split('\n');
            Int64 C;
            File.Create("c:\\2010CJR1.txt").Close();
            C = Int64.Parse(temp[0].Trim().Split(' ')[0]);
            for (int i = 0; i < C; i++)
            {

                Int64 N = Int64.Parse(temp[i * 3 + 1].Trim().Split(' ')[0]);
                Int64 K = Int64.Parse(temp[i * 3 + 1].Trim().Split(' ')[1]);
                Int64 B = Int64.Parse(temp[i * 3 + 1].Trim().Split(' ')[2]);
                Int64 T = Int64.Parse(temp[i * 3 + 1].Trim().Split(' ')[3]);

                Int64[] pos = new Int64[N];
                Int64[] speed = new Int64[N];

                for (int c = 0; c < N; c++)
                {
                    pos[c] = Int64.Parse(temp[i * 3 + 2].Trim().Split(' ')[c]);
                    speed[c] = Int64.Parse(temp[i * 3 + 3].Trim().Split(' ')[c]);
                }

                Int64 nonreachers = 0;
                Int64 swapsC = 0;
                Int64 reachers = 0;

                for (Int64 c = N - 1; c >= 0; c--)
                {
                    if (reachers == K)
                    {
                        break;
                    }

                    if ((pos[c] + speed[c] * T) >= B)
                    {
                        swapsC += nonreachers;
                        reachers++;
                    }
                    else
                    {
                        nonreachers++;
                    }
                }
                if (reachers >= K)
                {
                    File.AppendAllText("c:\\2010CJR1.txt", "Case #" + (i + 1).ToString() + ": " + swapsC.ToString() + "\n");
                    Console.WriteLine("Case #" + (i + 1).ToString() + ": " + swapsC.ToString() + "\n");
                }
                else
                {
                    File.AppendAllText("c:\\2010CJR1.txt", "Case #" + (i + 1).ToString() + ": IMPOSSIBLE\n");
                    Console.WriteLine("Case #" + (i + 1).ToString() + ": IMPOSSIBLE\n");
                }
            }

        }
    }
}
