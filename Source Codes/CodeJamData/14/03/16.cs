using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Jam
{
    class Program
    {
        string[] toArray(char[,] a, int r, int c)
        {
            string[] ret = new string[r];
            for (int n = 0; n < r; n++)
            {
                string tmp = "";
                for (int m = 0; m < c; m++)
                    tmp += a[n, m];
                ret[n] = tmp;
            }
            return ret;
        }
        string[] run(int r, int c, int m)
        {
            char[,] ret = new char[r, c];
            string[] imp = new string[] { "Impossible" };
            if (m == 0)
            {

                for (int p = 0; p < r; p++)
                    for (int q = 0; q < c; q++)
                        ret[p, q] = '.';
                ret[0, 0] = 'c';
                return toArray(ret, r, c);

            }
            if (r == 1)
            {
                ret[0, 0] = 'c';
                for (int q = 1; q < c; q++)
                    if (q < c - m)
                        ret[0, q] = '.';
                    else ret[0, q] = '*';
                return toArray(ret, r, c);
            }
            if (c == 1)
            {
                ret[0, 0] = 'c';
                for (int q = 1; q < r; q++)
                    if (q < r - m)
                        ret[q, 0] = '.';
                    else ret[q, 0] = '*';
                return toArray(ret, r, c);
            }
            if (m == 1)
            {
                if (c == 2 || r == 2) return imp;
                for (int p = 0; p < r; p++)
                    for (int q = 0; q < c; q++)
                        ret[p, q] = '.';
                ret[0, 0] = 'c';
                ret[r - 1, c - 1] = '*';
                return toArray(ret, r, c);
            }
            if (m == r * c - 1)
            {
                for (int p = 0; p < r; p++)
                    for (int q = 0; q < c; q++)
                        ret[p, q] = '*';
                ret[0, 0] = 'c';
                return toArray(ret, r, c);
            }

            for (int p = 0; p < r; p++)
                for (int q = 0; q < c; q++)
                    ret[p, q] = '*';


            if ((c == 2 || r == 2) && m % 2 == 1)
                return imp;

            if ((r * c - m) % 2 == 1 && (r * c - m) < 9)
                return imp;

            if ((r * c - m) % 2 == 0 && (r * c - m) < 4)
                return imp;

            int rem = (r * c - m);


            int[] next = new int[c];

            if (rem % 2 == 1)
            {
                for (int n = 0; n < 3; n++)
                    for (int p = 0; p < 3; p++)
                        ret[n, p] = '.';
                next[0] = 3;
                next[1] = 3;
                next[2] = 3;
                rem -= 9;
            }
            else
            {
                for (int n = 0; n < 2; n++)
                    for (int p = 0; p < 2; p++)
                        ret[n, p] = '.';
                next[0] = 2;
                next[1] = 2;
                rem -= 4;
            }

            while (rem > 0)
            {
                for (int p = 1; p < r && rem > 0; p++)
                    for (int q = 0; q < c - 1 && rem > 0; q++)
                        if (ret[p, q] != '.' && ret[p, q + 1] != '.' && ret[p - 1, q] == '.' && ret[p - 1, q + 1] == '.')
                        {
                            ret[p, q] = '.';
                            ret[p, q + 1] = '.';
                            rem -= 2;
                        }

                for (int p = 0; p < r - 1 && rem > 0; p++)
                    for (int q = 1; q < c && rem > 0; q++)
                        if (ret[p, q] != '.' && ret[p + 1, q] != '.' && ret[p, q - 1] == '.' && ret[p + 1, q - 1] == '.')
                        {
                            ret[p, q] = '.';
                            ret[p + 1, q] = '.';
                            rem -= 2;
                        }
            }

            ret[0, 0] = 'c';
            return toArray(ret, r, c);
        }
        static void Main(string[] args)
        {
            using (StreamReader f = new StreamReader("C-large.in"))
            {
                using (StreamWriter sw = new StreamWriter("C-large.out"))
                {
                    int cases = Int32.Parse(f.ReadLine());
                    for (int n = 0; n < cases; n++)
                    {

                        string[] tmp = f.ReadLine().Split(' ');

                        Program p = new Program();
                        string[] output = p.run(Int32.Parse(tmp[0]), Int32.Parse(tmp[1]), Int32.Parse(tmp[2]));

                        sw.WriteLine("Case #" + (n + 1).ToString() + ":");
                        for (int m = 0; m < output.Length; m++)
                            sw.WriteLine(output[m]);
                    }
                }
            }

        }
    }
}
