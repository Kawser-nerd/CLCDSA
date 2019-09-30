using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            string searchFor = "welcome to code jam";

            using (StreamReader srIn = new StreamReader("C-large.in"))
            {
                int N = int.Parse(srIn.ReadLine());

                using (StreamWriter swOut = new StreamWriter("C-large.out"))
                {
                    for (int caseNum = 0; caseNum < N; caseNum++)
                    {
                        Program p = new Program(srIn.ReadLine(), searchFor);
                        //Print output
                        swOut.WriteLine("Case #{0}: {1:0000}", caseNum + 1, p.Solve());
                    }
                }
            }
        }

        private string m_searchFor;
        private string m_input;
        private int[,] m_counts;
        private static int INVALID = -1;

        public Program(string input, string searchFor)
        {
            m_searchFor = searchFor;
            m_input = input;
            m_counts = new int[input.Length+1,m_searchFor.Length+1];
            for (int i = 0; i < input.Length + 1; i++)
            {
                for (int j = 0; j < m_searchFor.Length + 1; j++)
                {
                    m_counts[i, j] = INVALID;
                }
            }
        }

        public int Solve()
        {
            return Solve(m_input.Length, m_searchFor.Length);
        }

        public int Solve(int inputSubStringLength, int searchSubstringLength)
        {
            //If not cached
            if (m_counts[inputSubStringLength, searchSubstringLength] == INVALID)
            {
                if (inputSubStringLength == 0)
                {
                    m_counts[inputSubStringLength, searchSubstringLength] = 0;
                }
                else if (searchSubstringLength == 1)
                {
                    m_counts[inputSubStringLength, searchSubstringLength] = CountOfFirstLetter(inputSubStringLength);
                }
                else if (inputSubStringLength < searchSubstringLength)
                {
                    m_counts[inputSubStringLength, searchSubstringLength] = 0;
                }
                else if (m_input[inputSubStringLength - 1] == m_searchFor[searchSubstringLength - 1])
                {
                    int sameLengthOneLessProgress = Solve(inputSubStringLength, searchSubstringLength - 1);
                    int shorterAndSameProgress = Solve(inputSubStringLength - 1, searchSubstringLength);
                    m_counts[inputSubStringLength, searchSubstringLength] =
                        (sameLengthOneLessProgress
                        + shorterAndSameProgress) % 10000;
                }
                else
                {
                    m_counts[inputSubStringLength, searchSubstringLength] = Solve(inputSubStringLength - 1, searchSubstringLength);
                }
            }

            return m_counts[inputSubStringLength, searchSubstringLength];
        }

        private int CountOfFirstLetter(int end)
        {
            int count = 0;
            for (int i = 0; i < end; i++)
            {
                if (m_input[i] == m_searchFor[0])
                    count++;
            }
            return count;
        }
    }
}
