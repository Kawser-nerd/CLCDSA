using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using Number = System.Int64;

/***
 * WRITTEN BY ananda
 * for Code Jam 2017
 */
namespace codejam2017_standard
{
    class rect
    {
        public int r1, r2, c1, c2;
        public rect(int _r1, int _r2, int _c1, int _c2)
        {
            r1 = _r1;
            r2 = _r2;
            c1 = _c1;
            c2 = _c2;
        }
        public void recheck()
        {
            if (r1 > r2)
            {
                int x = r1;
                r1 = r2;
                r2 = x;
            }
            if (c1 > c2)
            {
                int x = c1;
                c1 = c2;
                c2 = x;
            }
        }
    }
    class Program
    {
        const string MAIN_FOLDER = @"D:\Computer\Programming\C#\Codejam\2017_1A\Input\";
        const string PROBLEM_NAME = "A-large.in";

        //----LOG
        static StreamWriter log_writer;
        static void add_log(string log)
        {
            log_writer.WriteLine(log);
        }

        static void Main(string[] args)
        {
            string now = DateTime.Now.Ticks.ToString();
            using (StreamReader reader = new StreamReader(MAIN_FOLDER + PROBLEM_NAME))
            using (StreamWriter writer = new StreamWriter(MAIN_FOLDER + PROBLEM_NAME + ".out"))
            using (log_writer = new StreamWriter(MAIN_FOLDER + PROBLEM_NAME + "_" + now + ".log"))
            {
                int T = int.Parse(reader.ReadLine());
                for (int i = 0; i < T; i++)
                {
                    add_log("case " + (i + 1));
                    int output = SOLVE_CASE(reader, writer, i);
                }
            }
        }

        static int SOLVE_CASE(StreamReader reader, StreamWriter writer, int caseNumber)
        {
            //-------------INPUT
            //first line
            var line = reader.ReadLine();
            string[] line_parts = line.Split(' ');
            int R = int.Parse(line_parts[0]),
                C = int.Parse(line_parts[1]);

            //read arrays or next tin0 lines
            string[,] tin = new string[R, C];
            Dictionary<string, rect> rects = new Dictionary<string, rect>();
            
            for (int i = 0; i < R; i++)
            {
                line = reader.ReadLine();
                for (int j = 0; j < C; j++)
                {
                    tin[i, j] = line.Substring(j, 1);
                    if (tin[i, j] != "?")
                    {
                        if(rects.ContainsKey(tin[i,j])){
                            rect f = rects[tin[i, j]];
                            if (i < f.r1) f.r1 = i;
                            if (i > f.r2) f.r2 = i;
                            if (j < f.c1) f.c1 = j;
                            if (j > f.c2) f.c2 = j;
                            rects[tin[i, j]] = f;
                        }else{
                            rect f = new rect(i,i,j,j);
                            f.recheck();
                            rects.Add(tin[i,j], f);
                        }
                    }
                }
            }
            refill_array(tin, rects);

            //check left
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    if (tin[i, j] == "?")
                    {
                        if (j != 0)
                        {
                            string k1 = tin[i, j - 1];
                            if (k1 != "?")
                            {
                                bool doit = true;
                                rect f = rects[k1];
                                for (int i2 = f.r1; i2 <= f.r2; i2++)
                                {
                                    if (tin[i2, j - 1] != k1)
                                        break;
                                    if (tin[i2, j] != "?")
                                    {
                                        doit = false;
                                        break;
                                    }
                                }
                                if (doit)
                                {
                                    f.c2++;
                                    refill_array(tin, rects);
                                }
                            }
                        }
                    }
                }
            }

            //check right
            for (int i = 0; i < R; i++)
            {
                for (int j = C-1; j >= 0; j--)
                {
                    if (tin[i, j] == "?")
                    {
                        if (j != C-1)
                        {
                            string k1 = tin[i, j + 1];
                            if (k1 != "?")
                            {
                                bool doit = true;
                                rect f = rects[k1];
                                for (int i2 = f.r1; i2 <= f.r2; i2++)
                                {
                                    if (tin[i2, j + 1] != k1)
                                        break;
                                    if (tin[i2, j] != "?")
                                    {
                                        doit = false;
                                        break;
                                    }
                                }
                                if (doit)
                                {
                                    f.c1--;
                                    refill_array(tin, rects);
                                }
                            }
                        }
                    }
                }
            }

            //check top
            for (int i = 1; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    if (tin[i, j] == "?")
                    {
                        string k1 = tin[i-1, j];
                        if (k1 != "?")
                        {
                            bool doit = true;
                            rect f = rects[k1];
                            for (int j2 = f.c1; j2 <= f.c2; j2++)
                            {
                                if (tin[i-1, j2] != k1)
                                    break;
                                if (tin[i, j2] != "?")
                                {
                                    doit = false;
                                    break;
                                }
                            }
                            if (doit)
                            {
                                f.r2++;
                                refill_array(tin, rects);
                            }
                        }
                    }
                }
            }

            //check down
            for (int i = R-2; i >= 0; i--)
            {
                for (int j = 0; j < C; j++)
                {
                    if (tin[i, j] == "?")
                    {
                        string k1 = tin[i + 1, j];
                        if (k1 != "?")
                        {
                            bool doit = true;
                            rect f = rects[k1];
                            for (int j2 = f.c1; j2 <= f.c2; j2++)
                            {
                                if (tin[i + 1, j2] != k1)
                                    break;
                                if (tin[i, j2] != "?")
                                {
                                    doit = false;
                                    break;
                                }
                            }
                            if (doit)
                            {
                                f.r1--;
                                refill_array(tin, rects);
                            }
                        }
                    }
                }
            }


            //---------------WRITE with cases
            
            writer.WriteLine("Case #{0}:", caseNumber + 1);
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C-1; j++)
                {
                    writer.Write(tin[i, j]);
                }
                writer.WriteLine(tin[i, C-1]);
            }

            return 0;
        }

        static void refill_array(string[,] tin, Dictionary<string, rect> rects)
        {
            foreach (KeyValuePair<string, rect> entry in rects)
            {
                rect f = entry.Value;
                string key = entry.Key;
                for (int i = f.r1; i <= f.r2; i++)
                {
                    for (int j = f.c1; j <= f.c2; j++)
                    {
                        tin[i, j] = key;
                    }
                }
            }
        }

    }
}
