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
    class Program
    {
        const string MAIN_FOLDER = @"D:\Computer\Programming\C#\Codejam\2017_1A\Input\";
        const string PROBLEM_NAME = "B-large.in";

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
            int I = int.Parse(line_parts[0]),
                P = int.Parse(line_parts[1]);

            float[,] ings = new float[I, 2];
            line = reader.ReadLine();
            line_parts = line.Split(' ');
            for (int i = 0; i < I; i++)
            {
                int t = int.Parse(line_parts[i]);
                ings[i, 0] = ((float)t) * 0.9f;
                ings[i, 1] = ((float)t) * 1.1f;
            }

            int[, ,] packs = new int[I, P, 2];
            for (int i = 0; i < I; i++)
            {
                line = reader.ReadLine();
                line_parts = line.Split(' ');
                for (int p = 0; p < P; p++)
                {
                    float t = float.Parse(line_parts[p]);
                    packs[i, p, 0] = (int)Math.Ceiling(t / ings[i, 1]);
                    packs[i, p, 1] = (int)Math.Floor(t / ings[i, 0]);
                }
            }

            //-------------SOLVE PROBLEM, with tin0=N,tin1,tin[0,0],...
            int res = 0;
            bool[,] used = new bool[I, P];
            while (true)
            {

                int max = 0;
                for (int p = 0; p < P; p++)
                {
                    if (used[0, p])
                        continue;
                    if (packs[0, p, 1] > max)
                        max = packs[0, p, 1];
                }

                if (max == 0)
                    break;

                //find smallest [p0 , max] for each I
                bool do_able = true;
                int[] p_keys = new int[I];
                for (int i = 0; i < I; i++)
                {
                    int p_key = -1;
                    int p_min = int.MaxValue;
                    for (int p = 0; p < P; p++)
                    {
                        if (used[i, p])
                            continue;
                        if (packs[i, p, 1] >= max && packs[i, p, 0] <= max)
                        {
                            if (max - packs[i, p, 0] < p_min)
                            {
                                p_min = max - packs[i, p, 0];
                                p_key = p;
                            }
                        }
                    }
                    if (p_key == -1)
                    {
                        do_able = false;
                        break;
                    }
                    p_keys[i] = p_key;
                }
                if (!do_able)
                {
                    for (int i = 0; i < I; i++)
                    {
                        for (int p = 0; p < P; p++)
                        {
                            if (packs[i, p, 1] == max)
                            {
                                packs[i, p, 1]--;
                                if (packs[i, p, 1] < packs[i, p, 0])
                                    used[i, p] = true;
                            }
                        }
                    }
                }
                if (do_able)
                {
                    res++;
                    for (int i = 0; i < I; i++)
                    {
                        used[i, p_keys[i]] = true;
                        packs[i, p_keys[i], 1]--;
                    }
                }
            }


            //---------------WRITE with cases
           
            writer.WriteLine("Case #{0}: {1}", caseNumber + 1, res.ToString());

            return 0;
        }

        static void put_def_value_into_array(int N, int N2, Number[,] array, Number def)
        {
            for (int i = 0; i < N; i++)
                for (int i2 = 0; i2 < N2; i2++)
                    array[i, i2] = def;
        }

    }
}
