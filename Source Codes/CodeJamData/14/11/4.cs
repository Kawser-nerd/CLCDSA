using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;
using System.IO;
using System.Threading;

namespace ConsoleApplication1
{
    class Program
    {
        static string Diff(string outlet, string device, out int switches)
        {
            string diff = "";
            switches = 0;
            for (int i = 0; i < outlet.Length; i++)
            {
                diff = diff + ( (outlet[i] == device[i]) ? '0' : '1' );
                switches += (outlet[i] == device[i]) ? 0 : 1;
            }
            return diff;
        }

        static string Switch(string outlet, string diff)
        {
            string res = "";
            for (int i = 0; i < outlet.Length; i++)
            {
                res += (outlet[i] == diff[i]) ? '0' : '1';
            }
            return res;
        }

        static string Solve(int N, int L, string[] outlets, string[] devices)
        {
            int res = L + 1;
            HashSet<string> deviceSet = new HashSet<string>(devices);
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                {
                    int cur = -1;
                    string diff = Diff(outlets[i], devices[j], out cur);
                    bool possible = true;
                    for (int k = 0; k < N; k++)
                    {
                        string pl = Switch(outlets[k], diff);
                        if (!deviceSet.Contains(pl))
                        {
                            possible = false;
                            break;
                        }
                    }
                    if (possible)
                    {
                        res = Math.Min(res, cur);
                    }
                }

            return (res == L + 1) ? "NOT POSSIBLE" : res.ToString();
        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            using (StreamReader sr = new StreamReader(args[0]))
            {
                int T = int.Parse(sr.ReadLine());
                for (int i = 0; i < T; i++)
                {
                    int[] splitted = sr.ReadLine().Split(' ').Select(s => int.Parse(s, CultureInfo.InvariantCulture)).ToArray();
                    int N = splitted[0];
                    int L = splitted[1];
                    string[] outlets = sr.ReadLine().Split(' ');
                    string[] devices = sr.ReadLine().Split(' ');
                    string res = Solve(N, L, outlets, devices);
                    Console.WriteLine(string.Format("Case #{0}: {1}", i + 1, res));
                }
            }
        }
    }
}
