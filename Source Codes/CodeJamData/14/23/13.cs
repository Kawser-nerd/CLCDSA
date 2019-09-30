using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C
{

    public class Solver
    {
        string answer;
        bool hasAnswer;
        int n,m;
        int[,] G = new int[51, 51];
        List<string> zip = new List<string>();
        int[] prev = new int[51];
        int[] p = new int[50];
        bool mark;

        public void Run()
        {
            using (FileStream input = new FileStream("C-small-attempt0.in", FileMode.Open))
            //using (FileStream input = new FileStream("input.txt", FileMode.Open))
            using (FileStream output = new FileStream("output.txt", FileMode.Create))
            using (StreamReader reader = new StreamReader(input))
            using (StreamWriter writer = new StreamWriter(output))
            {
                int test = Int32.Parse(reader.ReadLine());
                for (int tt = 0; tt < test; tt++)
                {
                    ReadInput(reader);
                    SolveTask(writer);
                    WriteOutput(writer, tt + 1);
                }
            }

        }

        private static bool NextPermutation(int[] numList, int len)
        {
            /*
             Knuths
             1. Find the largest index j such that a[j] < a[j + 1]. If no such index exists, the permutation is the last permutation.
             2. Find the largest index l such that a[j] < a[l]. Since j + 1 is such an index, l is well defined and satisfies j < l.
             3. Swap a[j] with a[l].
             4. Reverse the sequence from a[j + 1] up to and including the final element a[n].

             */
            var largestIndex = -1;
            for (var i = len - 2; i >= 0; i--)
            {
                if (numList[i] < numList[i + 1])
                {
                    largestIndex = i;
                    break;
                }
            }

            if (largestIndex < 0) return false;

            var largestIndex2 = -1;
            for (var i = len - 1; i >= 0; i--)
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

            for (int i = largestIndex + 1, j = len - 1; i < j; i++, j--)
            {
                tmp = numList[i];
                numList[i] = numList[j];
                numList[j] = tmp;
            }

            return true;
        }

        void dfs(StreamWriter writer)
        {
            int cur = 0;
            int pos = 1;

            prev[0] = -1;
            while (cur>=0 && pos<n)
            {
                if (G[p[cur],p[pos]]==1)
                {
                    prev[pos] = cur;
                    cur = pos;
                    //writer.WriteLine("{0} -> {1}", p[cur], p[pos]);
                    pos++;
                }
                else
                {
                    cur = prev[cur];
                }
            }
            if (pos>=n)
            {
                mark = true;
            }
        }

        private void SolveTask(StreamWriter writer)
        {
            hasAnswer = false;
            answer = "";
            for (int i=0;i<n;i++)
            {
                p[i] = i;
            }
            do
            {
                mark = false;
                dfs(writer);
                //writer.WriteLine();
                if (mark)
                {
                    StringBuilder str = new StringBuilder();
                    for (int i=0;i<n;i++)
                    {
                        str.Append(zip[p[i]]);
                    }
                    string s = str.ToString();
                    if (!hasAnswer || s.CompareTo(answer)<0)
                    {
                        hasAnswer = true;
                        answer = s;
                    }
                }
                /*for (int i=0;i<n;i++)
                {
                    writer.Write(p[i]);
                    writer.Write(' ');
                }
                writer.WriteLine();*/

            } while (NextPermutation(p, n));
        }

        private void WriteOutput(StreamWriter writer, int testNum)
        {
            //writer.WriteLine("{0} {1} {2}",A, B, C);
            writer.WriteLine(string.Format("Case #{0}: {1}", testNum, (hasAnswer) ? answer : "-1"));
        }

        private void ReadInput(StreamReader reader)
        {
            string[] str = reader.ReadLine().Split(' ');
            n = Int32.Parse(str[0]);
            m = Int32.Parse(str[1]);
            zip.Clear();
            for (int i = 0; i < n; i++)
            {
                zip.Add(reader.ReadLine());
                for (int j = 0; j < n; j++)
                {
                    G[i, j] = 0;
                }
            }
            for (int j = 0; j < m; j++)
            {
                string[] str2 = reader.ReadLine().Split(' ');
                int u = Int32.Parse(str2[0])-1;
                int v = Int32.Parse(str2[1])-1;
                G[u, v] = G[v, u] = 1;
            }
        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            (new Solver()).Run();
        }

    }
}
