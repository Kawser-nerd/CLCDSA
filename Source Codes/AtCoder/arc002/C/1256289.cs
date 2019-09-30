#if DEBUG
using Microsoft.VisualStudio.TestTools.UnitTesting;
#endif

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Globalization;
using System.Numerics;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var n = Int32.Parse(Console.ReadLine());
            var cmd = Console.ReadLine().ToCharArray();
            Console.WriteLine(GetAns(cmd));
        }

        static int GetAns(char[] cmd)
        {
            var ret = Int32.MaxValue;
            
            var keys = new char[] { 'A', 'B', 'X', 'Y' };
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        for (int l = 0; l < 4; l++)
                        {
                            var L = new char[] { keys[i], keys[j] };
                            var R = new char[] { keys[k], keys[l] };

                            ret = Math.Min(ret, GetAns(cmd, L, R));
                        }
                    }
                }
            }

            return ret;
        }

        static int GetAns(char[] cmd, char[] l, char[] r)
        {
            var ret = 0;

            for (int i = 0; i < cmd.Length; i++)
            {
                if (i == cmd.Length - 1)
                {
                    ret++;
                    break;
                }

                if (cmd[i] == l[0] && cmd[i + 1] == l[1])
                {
                    ret++;
                    i++;
                    continue;
                }

                if (cmd[i] == r[0] && cmd[i + 1] == r[1])
                {
                    ret++;
                    i++;
                    continue;
                }

                ret++;
            }

            return ret;
        }
    }
}