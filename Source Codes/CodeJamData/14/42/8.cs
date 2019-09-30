using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace UpAndDown
{
    class Program
    {
        static long MergeSortAndCountInversions<T>(List<T> l) where T : IComparable
        {
            if (l.Count == 0 || l.Count == 1)
            {
                return 0;
            }

            List<T> l1 = new List<T>(l.GetRange(0, l.Count / 2));
            List<T> l2 = new List<T>(l.GetRange(l.Count / 2, l.Count - l.Count / 2));

            long numInversions = MergeSortAndCountInversions<T>(l1);
            numInversions += MergeSortAndCountInversions<T>(l2);

            int index1 = 0;
            int index2 = 0;
            while (index1 < l1.Count || index2 < l2.Count)
            {
                if (index1 == l1.Count)
                {
                    l[index1 + index2] = l2[index2];
                    index2++;
                }
                else if (index2 == l2.Count)
                {
                    l[index1 + index2] = l1[index1];
                    index1++;
                    numInversions += index2;
                }
                else if (l1[index1].CompareTo(l2[index2]) <= 0)
                {
                    l[index1 + index2] = l1[index1];
                    index1++;
                    numInversions += index2;
                }
                else
                {
                    l[index1 + index2] = l2[index2];
                    index2++;
                }
            }

            return numInversions;
        }

        static int FindMaxIndex(List<int> l)
        {
            int max = -1;
            int maxIndex = -1;

            for (int i = 0; i < l.Count; i++)
            {
                if (l[i] > max)
                {
                    max = l[i];
                    maxIndex = i;
                }
            }

            return maxIndex;
        }

        static int FindMinIndex(List<int> l,int start,int end)
        {
            int min = Int32.MaxValue;
            int minIndex = -1;

            for (int i = start; i <= end; i++)
            {
                if (l[i] < min)
                {
                    min = l[i];
                    minIndex = i;
                }
            }

            return minIndex;
        }


        static long FindSolution(List<int> l)
        {
            int start = 0;
            int end = l.Count - 1;

            long numSwaps = 0;

            while (start < end)
            {
                int minIndex = FindMinIndex(l, start, end);

                if ((minIndex - start) <= end - minIndex)
                {
                    numSwaps += minIndex-start;
                    int min = l[minIndex];
                    l.RemoveAt(minIndex);
                    l.Insert(start, min);
                    start++;
                }
                else
                {
                    numSwaps += end - minIndex;
                    int min = l[minIndex];
                    l.RemoveAt(minIndex);                    
                    l.Insert(end, min);
                    end--;
                }
            }

            return numSwaps;
        }
        static void Main(string[] args)
        {

            //StreamReader sr = new StreamReader("D:\\a.txt");
            //StreamWriter sw = new StreamWriter("D:\\b.txt");

            //StreamReader sr = new StreamReader("D:\\B-small-attempt3.in");
            //StreamWriter sw = new StreamWriter("D:\\B-small-attempt3.out");

            StreamReader sr = new StreamReader("D:\\B-large.in");
            StreamWriter sw = new StreamWriter("D:\\B-large.out");


            int numTestCases = Convert.ToInt32(sr.ReadLine());

            for (int i = 0; i < numTestCases; i++)
            {

                Console.WriteLine(i);

                string[] str = sr.ReadLine().Split(' ');

                int N = Convert.ToInt32(str[0]);

                str = sr.ReadLine().Split(' ');
                List<int> nums = new List<int>();

                int max = -1;
                int maxIndex = -1;
                for (int j = 0; j < N; j++)
                {
                    nums.Add(Convert.ToInt32(str[j]));
                    if (nums[j] > max)
                    {
                        max = nums[j];
                        maxIndex = j;
                    }
                }

                long minSwaps = FindSolution(nums);
                

                sw.Write("Case #{0}: ", i + 1);

                sw.Write(minSwaps);

                sw.WriteLine();
            }

            sr.Close();
            sw.Close();
        }
    }
}
