using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Solvers
{
    class A : AbstractSolver
    {
        protected override void PreSolve()
        {
            String[] _in = { "zq ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv" };
            String[] _ou = { "qz our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up" };
            mapping = new Dictionary<char, char>();

            for (int i = 0; i < _in.Length; i++)
            {
                for (int c = 0; c < _in[i].Length; c++)
                {
                    mapping[_in[i][c]] = _ou[i][c];
                }
            }
        }

        Dictionary<char, char> mapping;

        protected override object Solve(System.IO.StreamReader input)
        {
            string humanLanguage = "";
            foreach (char c in NextLine())
            {
                humanLanguage += mapping[c];
            }
            return humanLanguage;
        }
    }
}
