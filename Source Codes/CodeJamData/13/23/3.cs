using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Solvers;
using GCJDevKit.Tools;
using System.Threading;
using System.IO;

namespace GCJDevKit.Solvers
{
    class C : AbstractSolver
    {
        const int INF = 1000000;

        String dictionaryFile = "C:\\Users\\User\\Downloads\\garbled_email_dictionary.txt";

        static List<String> dict;

        static int[,] score;

        static Tree root;

        static String currentInput;



        protected override void PreSolve()
        {
            dict = new List<string>();
            using (var input = new StreamReader(dictionaryFile))
            {
                String s;
                while ((s = input.ReadLine()) != null)
                {
                    dict.Add(s);
                }
            }

            root = new Tree();

            foreach (String s in dict)
            {
                root.append(s);
            }
        }

        protected override object Solve(System.IO.StreamReader input)
        {
            string s = NextWord();
            currentInput = s;

            score = new int[s.Length, 5];

            for (int i = 0; i < s.Length; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    score[i, j] = -1;
                }
            }

            for (int idx = s.Length - 1; idx > 0; idx--)
            {
                for (int ss = 4; ss > 0; ss--)
                {
                    calc(idx, ss);
                }
            }

            return calc(0, 0);
        }

        static int calc(int idx, int ile_dobrze)
        {
            if (score[idx, ile_dobrze] == -1)
            {
                score[idx, ile_dobrze] = root.solve(idx, ile_dobrze);
            }
            return score[idx, ile_dobrze];
        }

        class Tree
        {
            bool legal = false;

            Dictionary<char, Tree> subTrees = new Dictionary<char, Tree>();

            public void append(String w)
            {
                if (w.Length == 0)
                {
                    legal = true;
                }
                else
                {
                    char first = w[0];
                    if (!subTrees.ContainsKey(first))
                    {
                        subTrees[first] = new Tree();
                    }
                    subTrees[first].append(w.Substring(1));
                }
            }

            public int solve(int idx, int ile_dobrze)
            {
                if (idx == currentInput.Length)
                {
                    return legal ? 0 : INF;
                }

                if (ile_dobrze < 0) ile_dobrze = 0;
                int min = INF;
                if (legal)
                {
                    min = Math.Min(min, C.calc(idx, ile_dobrze));
                }

                if (ile_dobrze == 0)
                {
                    foreach (var entry in subTrees)
                    {
                    min = Math.Min(min, 1+ entry.Value.solve(idx + 1, 4));
                    }
                }
                if  (subTrees.ContainsKey(currentInput[idx]))
                {
                    min = Math.Min(min, subTrees[currentInput[idx]].solve(idx + 1, ile_dobrze - 1));
                }
                return min;
            }
        }
    }
}
