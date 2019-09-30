using System;
using System.Collections.Generic;

class Solver
{
    static Scanner cin;
    public Solver() {}
    public static int Main()
    {
        cin = new Scanner();
        new Solver().solve();
        return 0;
    }
    
    public bool ask(int x, int y) {
        Console.WriteLine("? {0} {1}", x, y);
        string s = cin.next();
        if (s == "Y") {
            return true;
        } else {
            return false;
        }
    }
 
    public void solve()
    {
        int a, b;
        a = cin.nextInt();
        b = cin.nextInt();
        int n = a + b;
        if (a <= b) {
            Console.WriteLine("Impossible");
            return;
        }
        var q = new List<int>();
        for (int i = 0; i < n; ++i) {
            if (q.Count == 0) {
                q.Add(i);
                continue;
            }
            if (ask(q[q.Count - 1], i)) {
                q.Add(i);
            } else {
                q.RemoveAt(q.Count - 1);
            }
        }
        int judge = q[q.Count - 1];
        var result = new List<int>(n);
        string answer = "! ";
        for (int i = 0; i < n; ++i) {
            if (ask(judge, i)) {
                answer += "1";
            } else {
                answer += "0";
            }
        }
        Console.WriteLine(answer);
        return;
    }
}

class Scanner
{
    string[] s;
    int i;
 
    char[] cs = new char[] { ' ' };
 
    public Scanner()
    {
        s = new string[0];
        i = 0;
    }
 
    public string next()
    {
        while (i >= s.Length)
        {
            string st = Console.ReadLine();
            while (st == "") st = Console.ReadLine();
            s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            i = 0;
        }
        return s[i++];
    }
 
    public int nextInt()
    {
        return int.Parse(next());
    }
 
    public long nextLong()
    {
        return long.Parse(next());
    }
 
    public double nextDouble()
    {
        return double.Parse(next());
    }
}