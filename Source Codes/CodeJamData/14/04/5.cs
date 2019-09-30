using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace DeceitfulWar
{
    class Program
    {
        static void Main(string[] args)
        {
            //StreamReader sr = new StreamReader("D:\\a.txt");
            //StreamWriter sw = new StreamWriter("D:\\b.txt");

            //StreamReader sr = new StreamReader("D:\\D-small-attempt0.in");
            //StreamWriter sw = new StreamWriter("D:\\D-small-attempt0_.out");

            StreamReader sr = new StreamReader("D:\\D-large.in");
            StreamWriter sw = new StreamWriter("D:\\D-large.out");

            int numTestCases = Convert.ToInt32(sr.ReadLine());
            Random r = new Random();
            for (int i = 0; i < numTestCases; i++)
            {
                string[] str = sr.ReadLine().Split(' ');

                int N = Convert.ToInt32(str[0]);
                
                double[] nums1 = new double[N];
                double[] nums2 = new double[N];
                
                str = sr.ReadLine().Split(' ');

                for (int j = 0; j < N; j++)
                {
                    nums1[j] = Double.Parse(str[j]);
                }

                str = sr.ReadLine().Split(' ');

                for (int j = 0; j < N; j++)
                {
                    nums2[j] = Double.Parse(str[j]);
                }

                int ww= FindWarWins(nums1, nums2);
                int dww = FindDeceitfulWarWins(nums1, nums2);

                sw.Write("Case #{0}: ", i + 1);
                sw.Write(dww.ToString() + " " + ww);
                sw.WriteLine();

            }
            sw.Close();
        }

        static int FindWarWins(double[] nums1, double[] nums2)
        {
            List<double> l1 = new List<double>(nums1);
            l1.Sort();
            l1.Reverse();

            List<double> l2 = new List<double>(nums2);
            l2.Sort();
            l2.Reverse();

            int N = l1.Count;
            for (int j = N - 1; j >= 0; j--)
            {
                bool found = false;
                for (int k = l2.Count - 1; k >= 0; k--)
                {
                    if (l2[k] > l1[j])
                    {
                        l1.RemoveAt(j);
                        l2.RemoveAt(k);
                        found = true;
                        break;
                    }
                }

                if (found == false) break;
            }

            return l1.Count;
        }

        static int FindDeceitfulWarWins(double[] nums1, double[] nums2)
        {
            List<double> l1 = new List<double>(nums1);
            l1.Sort();
            l1.Reverse();

            List<double> l2 = new List<double>(nums2);
            l2.Sort();

            int N = l1.Count;

            int numPoints = 0;

            for (int j = N - 1; j >= 0; j--)
            {
                if (l1[j] > l2[0])
                {
                    l1.RemoveAt(j);
                    l2.RemoveAt(0);
                    numPoints++;
                }
                else if (l1[j] < l2[j])
                {
                    l1.RemoveAt(j);
                    l2.RemoveAt(j);
                }
                else
                {
                    break;
                }

            }

            return numPoints + l1.Count;
        }
    }
}
