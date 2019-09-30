using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class PropperShuffle
    {
        static StreamReader Input;
        static StreamWriter Output;

        static string name;
        static long n;

        static Random rnd = new Random();

        static void Main(string[] args)
        {
            string classname = MethodBase.GetCurrentMethod().DeclaringType.Name;
            string testcase = Console.ReadLine();

            Input = new StreamReader("input/" + classname + "-" + testcase + ".txt");
            Output = new StreamWriter("output/" + classname + "-" + testcase + ".txt");

            int testcases = Convert.ToInt32(Input.ReadLine());
            //int testcases = 120000;
            int correct = 0;

            for (long tc = 1; tc <= testcases; tc++)
            {
                bool isGood;
                //int n = 1000;
                //int[] a = new int[n];

                int n = Convert.ToInt32(Input.ReadLine());
                string[] input = Input.ReadLine().Split(' ');
                int[] a = new int[n];

                for (int i = 0; i < n; i++)
                {
                    a[i] = Convert.ToInt32(input[i]);
                }

                /*if (rnd.Next(0, 2) < 1)
                {
                    isGood = true;
                    a = GenerateGood(n);
                }
                else
                {
                    isGood = false;
                    a = GenerateBad(n);
                }*/

                int med = 0;
                for (int i = 0; i < n * 0.4; i++)
                {
                    med += (a[i] - i + n + n) % n;
                }

                bool predictGood;
                if (med < 193190)
                    predictGood = false;
                else
                    predictGood = true;

                //if (isGood == predictGood)
                //    ++correct;                

                if (predictGood)
                    Output.WriteLine("Case #{0}: {1}", tc, "GOOD");
                else
                    Output.WriteLine("Case #{0}: {1}", tc, "BAD");
            }

            Output.Close();
        }

        static int[] GenerateGood(int n)
        {
            int[] a = new int[n];

            for (int i = 0; i < n; i++)
			{
			    a[i] = i;
			}
            for (int i = 0; i < n; i++)
			{
			    int r = rnd.Next(i, n);

                int swap = a[i];
                a[i] = a[r];
                a[r] = swap;
			}

            return a;
        }

        static int[] GenerateBad(int n)
        {
            int[] a = new int[n];

            for (int i = 0; i < n; i++)
            {
                a[i] = i;
            }
            for (int i = 0; i < n; i++)
            {
                int r = rnd.Next(0, n);

                int swap = a[i];
                a[i] = a[r];
                a[r] = swap;
            }

            return a;
        }
    }
}
