using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class A : Solution
{
    int n, m;
    string[] olddirs, newdirs;

    public override void Init(System.IO.TextReader r)
    {
        string[] z = r.ReadLine().Split(' ');
        n = int.Parse(z[0]);
        m = int.Parse(z[1]);
        olddirs = new string[n];
        newdirs = new string[m];

        for (int i = 0; i < n; i++)
            olddirs[i] = r.ReadLine();
        for (int i = 0; i < m; i++)
            newdirs[i] = r.ReadLine();
    }

    public override string Solve()
    {
        string ret = "";

        Dictionary<string, int> dirs = new Dictionary<string, int>();
        int cnt = 0;

        dirs["/"] = 1;

        foreach (string s in olddirs)        
        {
            dirs[s] = 1;
        }

        foreach (string z in newdirs)
        {
            string[] parts = z.Split('/');

            string path = "";

            foreach (string q in parts)
            {
                if (q == "") continue;
                path = path + "/" + q;
                if (!dirs.ContainsKey(path))
                {
                    dirs[path] = 1;
                    cnt++;
                }
            }
        }
        return cnt.ToString();
    }
}
