using System;

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
 
    public void solve()
    {
        long x;
        x = cin.nextLong();
        int ans = (int)(Math.Ceiling(Math.Sqrt(2 * x + 0.25) - 0.5) + 1e-9);
        Console.WriteLine(ans);
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