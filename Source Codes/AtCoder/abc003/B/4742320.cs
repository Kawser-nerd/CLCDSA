using System;
using System.Collections.Generic;
using static System.Console;
using System.Linq;
using System.IO;

namespace ConsoleApp2
{
    class Program {
        static decimal C(int a,int b) {
            decimal res = 1;
            for (int i = 0; i < b; i++) {
                res *= (a - i);
                res /= (i + 1);
            }
            return res;
        }


        static void Main(string[] Args) {
            string win = "You can win";
            string lose = "You will lose";
            string atcoder = "atcoder";

            string S = ReadLine();
            string T = ReadLine();

            if (S.Length != T.Length) {
                WriteLine(lose);
                goto ProgramEndPointLabel;
            }

            for (int i = 0; i < S.Length; i++) {
                if(S[i] != T[i]) {
                    if(S[i] == '@' || T[i] == '@') {
                        if(!(atcoder.Contains(S[i]) || atcoder.Contains(T[i]))){
                            WriteLine(lose);
                            goto ProgramEndPointLabel;
                        }
                    } else {
                        WriteLine(lose);
                        goto ProgramEndPointLabel;
                    }
                }
            }
            WriteLine(win);

            ProgramEndPointLabel:;

            ReadLine();
        }
    }
}