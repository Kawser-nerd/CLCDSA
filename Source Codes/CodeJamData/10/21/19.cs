using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace _2010CJR0
{
    class R1P1
    {
        static void Main(string[] args)
        {
            String fileData = File.ReadAllText("c:\\DataR1_1_T.txt");
            String[] temp = fileData.Split('\n');
            int T;
            File.Create("c:\\2010CJR1.txt").Close();
            T = Int32.Parse(temp[0].Split(' ')[0]);
            Int64 curPos = 1;
            for (int i = 0; i < T; i++)
            {
                Int64 res = 0;

                Int32 N = Int32.Parse(temp[curPos].Split(' ')[0]);
                Int32 M = Int32.Parse(temp[curPos].Split(' ')[1]);
                curPos++;

                List<String> exist = new List<string>();

                for (int c = 0; c < N; c++)
                {
                    String[] dirs = temp[curPos++].Trim().Split('/');
                    String path = "";
                    foreach (String tt in dirs)
                    {
                        if (tt.Length > 0)
                        {
                            path = path + "/" + tt;
                            exist.Add(path);
                        }
                    }
                }

                for (int c = 0; c < M; c++)
                {
                    String[] dirs = temp[curPos++].Trim().Split('/');
                    String path = "";
                    foreach (String tt in dirs)
                    {
                        if (tt.Length > 0)
                        {
                            path = path + "/" + tt;
                            if (!exist.Contains(path))
                            {
                                exist.Add(path);
                                res++;
                            }
                        }
                    }
                }

                File.AppendAllText("c:\\2010CJR1.txt", "Case #" + (i + 1).ToString() + ": " + res.ToString() + "\n");
                Console.WriteLine("Case #" + (i + 1).ToString() + ": " + res.ToString() + "\n");

            }

        }
    }
}
