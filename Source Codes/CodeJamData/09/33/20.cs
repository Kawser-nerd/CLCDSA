using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;
using System.IO;

namespace proyecto
{
    class Round1C_3
    {
        int N;
        int P, Q;
        int res;
        string file = "3";
        string input_file = "inputs\\round1c_in\\";
        string output_file = "outputs\\round1c_out\\";
        string input_extension = ".in";
        string output_extension = ".out";
        string strInput;
        int max = 500;
        bool[] arr;
        Hashtable mins;

        protected int minSeg(int ini, int fin)
        {
            if (fin < ini)
                return 0;

            if (mins[ini.ToString() + "_" + fin.ToString()] != null)
                return (int)mins[ini.ToString() + "_" + fin.ToString()];
            bool segmento = false;
            int min = -1;
            int r;

            for (int i = ini; i <= fin; i++)
            {
                if (arr[i])
                {
                    r = minSeg(ini, i - 1) + minSeg(i + 1, fin)+fin - ini;
                    if (!segmento)
                    {
                        min = r;
                    }
                    if (r < min)
                        min = r;
                    segmento = true;

                }
            }


            if (!segmento)
            {
                mins.Add(ini.ToString() + "_" + fin.ToString(), 0);
                return 0;
            }

            mins.Add(ini.ToString() + "_" + fin.ToString(), min);
            return min;
        }

        public void resolver()
        {
            StreamReader r = new StreamReader(input_file + file + input_extension);
            StreamWriter w = new StreamWriter(output_file + file + output_extension);
            arr = new bool[10003];
            N = int.Parse(r.ReadLine());
            string[] arrC;
            mins = new Hashtable();
            for (int iCase = 0; iCase < N; iCase++)
            {
                mins.Clear();
                strInput = r.ReadLine();
                arrC = strInput.Split(new char[] { ' ' });
                P = int.Parse(arrC[0]);
                Q = int.Parse(arrC[1]);

                strInput = r.ReadLine();
                arrC = strInput.Split(new char[] { ' ' });

                for (int iarr = 0; iarr < P; iarr++)
                {
                    arr[iarr] = false;
                }

                for (int iq = 0; iq < Q; iq++)
                {
                    arr[int.Parse(arrC[iq])-1] = true;
                }
                res = minSeg(0, P - 1);
                w.WriteLine("Case #" + (iCase + 1) + ": " + res.ToString());
            }


            r.Close();
            w.Close();
        }
    }
}
