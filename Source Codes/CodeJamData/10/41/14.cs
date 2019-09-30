using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;
using System.Numerics;
using System.Diagnostics;

namespace GCJ2010
{
    class Program
    {
        static void Solve()
        {
            int T = int.Parse(GCJ.ReadLine());

            for (int t = 1; t <= T; t++)
            {
                int k = int.Parse(GCJ.ReadLine());

                List<Dictionary<int, int>> dia = new List<Dictionary<int, int>>();
                for (int i = 0; i < k*2-1; i++)
                {
                    string[] ss = GCJ.ReadLine().Split(' ');
                    Dictionary<int, int> xs = new Dictionary<int, int>();
                    int x = -i;
                    if( i>=k )
                        x=-(2*k-1-i-1);
                    foreach (var s in ss)
                        if (s.Length > 0)
                        {
                            xs.Add(x,int.Parse(s));
                            x += 2;
                        }
                    dia.Add(xs);
                }

                var ans = _test(dia,k);

                GCJ.WriteLine(String.Format("Case #{0}: {1}", t, ans));
            }
        }
        static int _test(List<Dictionary<int,int>> dia,int k)
        {
            int y =0;
            for (;y<=k-2;y++)
            {
                if( _by(dia,k,k-1-y)||_by(dia,k,k-1+y))
                    break;
            }

            int x = 0;
            for (;x<=k-2; x++)
            {
                if (_bx(dia, k, - x) || _bx(dia, k,x))
                    break;
            }

            Debug.WriteLine("x.y " + x + " " + y);
            
            return (k + x+y) * (k + x+y) - k * k;
        }

        static bool _by(List<Dictionary<int, int>> dia, int k, int y)
        {
            if (y <= k - 1)
            {
                for (int i = 0; i < y; i++)
                {
                    foreach(var x in dia[i].Keys)
                        if( dia[i][x] != dia[2*y-i][x] )
                            return false;
                }
            }
            else
            {
                for (int i = y+1; i < 2*k-1; i++)
                {
                    foreach (var x in dia[i].Keys)
                        if (dia[i][x] != dia[2 * y - i][x])
                            return false;
                }
            }
            return true;
        }

        static bool _bx(List<Dictionary<int, int>> dia, int k, int x)
        {
            if (x < 0)
            {
                for (int y = -x+1; y <= 2 * k - 2 - (-x + 1); y++)
                {
                    for (int i =Math.Max(-y,-2*(k-1)+y);i<=x-1;i++)
                    {
                        if (!dia[y].ContainsKey(i))
                            continue; 
                        if (dia[y][i] != dia[y][2 * x - i])
                            return false;
                    }
                }
            }
            else
            {
                for (int y = x + 1; y <= 2 * k - 2 - (x + 1); y++)
                {
                    for (int i =Math.Min(y,2*(k-1)-y); i >x; i--)
                    {
                        if (!dia[y].ContainsKey(i))
                            continue;
                        if (dia[y][i] != dia[y][2 * x - i])
                            return false;
                    }
                }
            }
            return true;
        }


        static void Main(string[] args)
        {
            //_SetTarget();
            //_SetTarget("A-small-attempt1.in");
            _SetTarget("A-large.in");
            //_SetTarget("B-small-practice.in");
        }

        static void _SetTarget()
        {
string sample = @"
5
3
  1
 2 3
4 5 6
 7 8
  9
1
0
2
 1
2 2
 1
2
 1
1 2
 1
3
  1
 6 3
9 5 5
 6 3
  1

";
            GCJ = new GCJUtils();
            GCJ.SetSample(sample);
            Solve();
            GCJ.Close();
        }
        static void _SetTarget(string inputFileName)
        {
            GCJ = new GCJUtils();
            GCJ.SetInput(inputFileName);
            Solve();
            GCJ.Close();
        }

#region tools

        static GCJUtils GCJ;
        
        public class GCJUtils
        {
            public string ReadLine()
            {
                string ret = null;
                if (_sample != null)
                {
                    if (_sample.Count == 0)
                        return null;
                    ret = _sample[0];
                    _sample.RemoveAt(0);
                }  else 
                    ret = _sr.ReadLine();
                return ret.Replace("\n", "");
            }

            public void WriteLine(object o)
            {
                System.Diagnostics.Debug.WriteLine(o);
                if (_sample != null)
                    return;
                _sw.WriteLine(o);
            }

            public void SetSample(string sample)
            {
                _sample = new List<string>();
                string[] ss =sample.Split('\r');
                for (int i = 1; i <= ss.Length - 2; i++)
                {
                    _sample.Add(ss[i]);
                }
            }
            public void SetInput(string inputFileName)
            {
                //string iPath = Path.Combine(@"C:\Users\k\Downloads",inputFileName);
                string iPath = Path.Combine(@"D:\contest\GCJ2010\GCJ2010\R2", inputFileName);
                string oPath = Path.Combine(@"D:\contest\GCJ2010\GCJ2010\R2", inputFileName + ".out");
                _sr = new System.IO.StreamReader(iPath);
                _sw = new StreamWriter(oPath);
            }

            public void Close()
            {
                if( _sr!=null)
                    _sr.Close();
                if( _sw!=null)
                    _sw.Close();
            }
            List<string> _sample = null;
            System.IO.StreamReader _sr=null;
            System.IO.StreamWriter _sw=null;
        }
#endregion

    }
}
