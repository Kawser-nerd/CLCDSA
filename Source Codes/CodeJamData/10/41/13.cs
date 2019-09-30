using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
namespace R210A
{
    class Program
    {
        static List<string> outLines = new List<string>();

        static string file = "A-large";
        static void Main(string[] args)
        {
            StreamReader f = new StreamReader(file + ".in");
            string s = f.ReadLine();
            string[] subs = s.Split(' ');
            s = subs[0];
            int numCase = int.Parse(s);
            //s = subs[1];
            //int numSetup = int.Parse(s);
            //s = subs[2];
            //int someConstant = int.Parse(s);
            //for (int i = 0; i < numSetup; i++)
            //{
            ////create some sort of data structure to use
            //}
            for (int i = 0; i < numCase; i++)
            {
                int diamondsize = int.Parse(f.ReadLine());
                int[,] squares = new int[diamondsize,diamondsize];
                for (int j = 0; j < diamondsize * 2 - 1; j++)
                {
                    subs = f.ReadLine().Trim().Split(' ');
                    int start = j;
                    int add = 0;
                    if (start >= diamondsize)
                    {
                        start = diamondsize - 1;
                        add = j - diamondsize + 1;
                    }
                    for (int k = 0; k < subs.Length; k++)
                    {
                        squares[start - k, k + add] = int.Parse(subs[k]);

                    }
                }
                // get all the data for your case here
                computeCase(i + 1, diamondsize, squares);
            }
            f.Close();



            StreamWriter output = new StreamWriter(file + ".out");
            foreach (string l in outLines)
            {
                output.WriteLine(l);
            }
            output.Close();
        }
        public static void computeCase(int c, int size, int[,] original)
        {
            int horiz = 0;
            int vert = 0;
            if (size == 1)
            {
                outLines.Add("Case #" + c.ToString() + ": 0");
                return;
            }
            for (int l = 0; l < size - 1; l++)
            {
                // horizontal, above middle
                bool workhm = true;
                bool workhb = true;
                bool workvm = true;
                bool workvb = true;
                for (int i = 0; i < l + 1; i++)
                {
                    for (int j = 0; j < l + 1 - i; j++)
                    {
                        if (original[i, j] != original[l - j + 1, l - i + 1])
                            workhm = false;
                        if (original[size - i - 1, size - j - 1] != original[size - 1 - l + j - 1, size - 1 - l + i - 1])
                            workhb = false;

                        if (original[size - 1 - i, j] != original[size - 1 - l + j - 1, l - i + 1])
                            workvm = false;
                        if (original[i, size - j - 1] != original[l - j + 1, size - 1 - l + i - 1])
                            workvb = false;
                    }
                }
                if ((workvb || workvm) && l >= vert)
                    vert = l+1;
                if ((workhb || workhm) && l >= horiz)
                    horiz = l+1;

            }

            int ans = 3 * size - 2 - vert - horiz;
            outLines.Add("Case #" + c.ToString() + ": " + (ans*ans - size*size).ToString());


        }
    }
}
