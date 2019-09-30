using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC_C
{
    class C076
    {
        static void Main(string[] args)
        {
            string S0 = Console.ReadLine();
            string T = Console.ReadLine();

            string S = "";
            if (T.Length > S0.Length) S = "UNRESTORABLE";
            if (S == "")
            {
                for (int i = 0; i <= S0.Length - T.Length; i++)
                {
                    bool match = true;
                    for (int j = 0; j < T.Length; j++)
                    {
                        if (!(S0[i + j] == T[j] || S0[i + j] == '?'))
                        {
                            match = false;
                            break;
                        }
                    }
                    if (match)
                    {
                        S = S0.Substring(0, i) + T + S0.Substring(i + T.Length);
                        S = S.Replace('?', 'a');
                    }
                }
            }
            if (S == "") S = "UNRESTORABLE";
            Console.WriteLine(S);
        }
    }
}