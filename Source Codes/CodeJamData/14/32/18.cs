using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Round1C_2
{
    class Program
    {
        static void Main(string[] args)
        {
            var file = new StreamReader(@"C:\Users\Administrator\Documents\CodeJam\r1_2_3.txt");
            var outFile = new StreamWriter(@"C:\Users\Administrator\Documents\CodeJam\r1_2_3Out.txt");
            var total = long.Parse(file.ReadLine());

            for (long i = 1; i <= total; i++)
            {
                long carLen = long.Parse(file.ReadLine());
                var lineSplit = file.ReadLine().Split(' ');

                
                var ints = new int[carLen];

                for (int j = 0; j < carLen; j++)
                    ints[j] = j;

                for (int j = 0; j < carLen; j++)
                {
                    var str = lineSplit[j];
                    string res = str[0].ToString();
                    for(int k = 1; k< str.Length;k++)
                        if(res[res.Length-1] != str[k])
                            res += str[k];
                    lineSplit[j] = res;

                }
                long nPerm = CheckList(lineSplit, ints)?1:0;

                while (NextPermutation(ints))
                {
                    if (CheckList(lineSplit, ints))
                        nPerm++;
                }

                outFile.WriteLine(string.Format("Case #{0}: {1}", i, nPerm));
                Console.WriteLine(i);

            }

            file.Close();
            outFile.Close();
        }

        private static bool CheckList(string[] strList, int[] ints)
        {
            var charSet = new HashSet<char>();
            char? prevChar = null;
            foreach (int i in ints)
            {
                var str = strList[i];
                foreach (char c in str)
                {
                    if (prevChar == null)
                    {
                        prevChar = c;
                        charSet.Add(c);
                        continue;
                    }

                    if (prevChar == c)
                    {
                        continue;
                    }
                    else
                    {
                        if (charSet.Contains(c))
                        {
                            return false;
                        }
                        else
                        {
                            charSet.Add(c);
                            prevChar = c;
                        }
                    }
                    
                }
            }

            return true;
        }

        private static bool NextPermutation(int[] numList)
        {
            /*
             Knuths
             1. Find the largest index j such that a[j] < a[j + 1]. If no such index exists, the permutation is the last permutation.
             2. Find the largest index l such that a[j] < a[l]. Since j + 1 is such an index, l is well defined and satisfies j < l.
             3. Swap a[j] with a[l].
             4. Reverse the sequence from a[j + 1] up to and including the final element a[n].

             */
            var largestIndex = -1;
            for (var i = numList.Length - 2; i >= 0; i--)
            {
                if (numList[i] < numList[i + 1])
                {
                    largestIndex = i;
                    break;
                }
            }

            if (largestIndex < 0) return false;

            var largestIndex2 = -1;
            for (var i = numList.Length - 1; i >= 0; i--)
            {
                if (numList[largestIndex] < numList[i])
                {
                    largestIndex2 = i;
                    break;
                }
            }

            var tmp = numList[largestIndex];
            numList[largestIndex] = numList[largestIndex2];
            numList[largestIndex2] = tmp;

            for (int i = largestIndex + 1, j = numList.Length - 1; i < j; i++, j--)
            {
                tmp = numList[i];
                numList[i] = numList[j];
                numList[j] = tmp;
            }

            return true;
        }
    }
}
