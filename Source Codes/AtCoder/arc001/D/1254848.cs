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
            var ans = new char[8][];

            var qcnt = 0;
            for (int i = 0; i < 8; i++)
            {
                ans[i] = Console.ReadLine().ToCharArray();
                qcnt += ans[i].Count(c => c == 'Q');
            }

            if (GetAns(ans, qcnt))
            {
                foreach (var a in ans) Console.WriteLine(a);
            }
            else
            {
                Console.WriteLine("No Answer");
            }
        }

        static bool GetAns(char[][] ans, int qcnt)
        {
            if (!IsValid(ans)) return false;
            if (qcnt == 8) return true;

            for (int row = 0; row < 8; row++)
            {
                for (int col = 0; col < 8; col++)
                {
                    if (ans[row][col] == 'Q') continue;

                    ans[row][col] = 'Q';
                    if (GetAns(ans, qcnt + 1)) return true;
                    ans[row][col] = '.';
                }
            }

            return false;
        }

        static bool IsValid(char[][] ans)
        {
            for (var col = 0; col < 8; col++)
            {
                for (var row = 0; row < 8; row++)
                {
                    if (ans[row][col] != 'Q') continue;

                    //vartical
                    for (int r2 = 0; r2 < 8; r2++)
                    {
                        if (r2 == row) continue;
                        if (ans[r2][col] == 'Q') return false;
                    }

                    //horizontal
                    for (int c2 = 0; c2 < 8; c2++)
                    {
                        if (c2 == col) continue;
                        if (ans[row][c2] == 'Q') return false;
                    }

                    //diagonal

                    // top-left -> bottom-right
                    var r = row - 1;
                    var c = col - 1;
                    while (r >= 0 && c >= 0)
                    {
                        if (ans[r][c] == 'Q') return false;
                        r--;
                        c--;
                    } 
                    r = row + 1;
                    c = col + 1;
                    while (r < 8 && c < 8)
                    {
                        if (ans[r][c] == 'Q') return false;
                        r++;
                        c++;
                    }

                    // bottom-left -> top-right
                    r = row + 1;
                    c = col - 1;
                    while (r < 8 && c >= 0)
                    {
                        if (ans[r][c] == 'Q') return false;
                        r++;
                        c--;
                    }
                    r = row - 1;
                    c = col + 1;
                    while (r >= 0 && c < 8)
                    {
                        if (ans[r][c] == 'Q') return false;
                        r--;
                        c++;
                    }
                }
            }

            return true;
        }
    }
}