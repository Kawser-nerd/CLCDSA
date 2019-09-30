using System;
using System.Collections.Generic;
using System.IO;

namespace GCJ
{
    public class Rotate
    {
        public static void Main(string[] args)
        {
            var file = File.OpenText("A-large.in");
            var output = File.CreateText("A-large_out.txt");
            var t = int.Parse(file.ReadLine());
            for (int tc = 0; tc < t; tc++)
            {
                var temp = file.ReadLine().Split(new[] { " " }, StringSplitOptions.RemoveEmptyEntries);
                var n = int.Parse(temp[0]);
                var k = int.Parse(temp[1]);
                var b = new List<string>();
                for (int i = 0; i < n; i++)
                {
                    b.Add(file.ReadLine());
                }
                var m = new int[n,n];
                for (int i = 0; i < n; i++)
                {
                    var sp = 0;
                    for (int j = 0; j < n; j++)
                    {
                        var c = b[n - i - 1][n - j - 1];
                        if (c == 'R')
                        {
                            m[n - sp - 1, i] = 1;
                            ++sp;
                        }
                        else if (c == 'B')
                        {
                            m[n - sp - 1, i] = 2;
                            ++sp;
                        }
                    }
                }
                var cr = Check(m, n, k, 1);
                var cb = Check(m, n, k, 2);
                if (cr && cb)
                {
                    output.WriteLine("Case #" + (tc + 1) + ": Both");
                }
                else if (cr)
                {
                    output.WriteLine("Case #" + (tc + 1) + ": Red");
                }
                else if (cb)
                {
                    output.WriteLine("Case #" + (tc + 1) + ": Blue");
                }
                else
                {
                    output.WriteLine("Case #" + (tc + 1) + ": Neither");
                }
            }
            output.Close();
        }

        private static bool Check(int[,] m, int n, int k, int x)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (m[n - i - 1, j] == x)
                    {
                        var found = true;
                        for (int l = 1; l < k; l++)
                        {
                            if (n - i - 1 - l < 0 ||  j - l < 0 || m[n - i - 1 - l, j - l] != x)
                            {
                                found = false;
                                break;
                            }
                        }
                        if (found)
                            return true;
                        found = true;
                        for (int l = 1; l < k; l++)
                        {
                            if (n - i - 1 - l < 0 || m[n - i - 1 - l, j] != x)
                            {
                                found = false;
                                break;
                            }
                        }
                        if (found)
                            return true;
                        found = true;
                        for (int l = 1; l < k; l++)
                        {
                            if (n - i - 1 - l < 0 || j + l >= n || m[n - i - 1 - l, j + l] != x)
                            {
                                found = false;
                                break;
                            }
                        }
                        if (found)
                            return true;
                        found = true;
                        for (int l = 1; l < k; l++)
                        {
                            if (j - l < 0 || m[n - i - 1, j - l] != x)
                            {
                                found = false;
                                break;
                            }
                        }
                        if (found)
                            return true;
                        found = true;
                        for (int l = 1; l < k; l++)
                        {
                            if (j + l >= n || m[n - i - 1, j + l] != x)
                            {
                                found = false;
                                break;
                            }
                        }
                        if (found)
                            return true;
                    }
                }
            }
            return false;
        }
    }
}
