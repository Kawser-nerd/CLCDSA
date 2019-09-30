using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

class Program
{
    void Run()
    {
        StreamReader sr = new StreamReader(@"D:\Temporary Files\Mary's HDrive\G-remain-backup\Contest 2013\GCJ\Q\b.in");
        StreamWriter so = new StreamWriter(@"D:\Temporary Files\Mary's HDrive\G-remain-backup\Contest 2013\GCJ\Q\b.out");
        int _ = Convert.ToInt32(sr.ReadLine());
        for (int t = 1; t <= _; t++)
        {
            String[] str = sr.ReadLine().Split(' ');
            int n = Convert.ToInt32(str[0]), m = Convert.ToInt32(str[1]);
            int[][] a = new int[n][];
            for (int i = 0; i < n; i++)
            {
                a[i] = new int[m];
                int j=0;
                foreach (String p in sr.ReadLine().Split(' '))
                    a[i][j++] = Convert.ToInt32(p);
            }
            bool flag = false;
            for (int h = 1; h < 100; h++)
            {
                bool[] row = new bool[n], column = new bool[m];
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < m; j++)
                        if (a[i][j] > h)
                        {
                            row[i] = true;
                            column[j] = true;
                        }
                for(int i=0; i<n; i++)
                    for(int j=0; j<m; j++)
                        if (a[i][j] <= h && row[i] && column[j])
                        {
                            flag = true;
                            goto End;
                        }
            }
        End:
            so.WriteLine("Case #{0}: {1}", t, !flag ? "YES" : "NO");
        }
        so.Close();
    }
    static void Main(string[] args)
    {
        new Program().Run();
    }
}