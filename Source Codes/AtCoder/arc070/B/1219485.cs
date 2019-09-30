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
        int n, k;
        n = cin.nextInt();
        k = cin.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = cin.nextInt();
        }
        Array.Sort(a);
        int lb = lowerBound(a, k);
        if (lb == 0) {
            Console.WriteLine(0);
            return;
        }
        
        Array.Resize(ref a, lb);
        int sumUnderK = 0;
        for (int i = 0; i < lb; ++i) {
            sumUnderK += a[i];
        }
        if (sumUnderK < k) {
            Console.WriteLine(lb);
            return;
        }
        
        Array.Reverse(a);
        int answerLowest = k;
        bool[] dp = new bool[k];
        for (int i = 0; i < k; ++i) {
            dp[i] = false;
        }
        dp[0] = true;
        int possibleMax = 0;
        for (int i = 0; i < lb; ++i) {
            if (k - a[i] <= possibleMax) {
              answerLowest = a[i];
            }
         
            for (int j = k - a[i] - 1; j >= 0; --j) {
                if (dp[j]) {
                    dp[j + a[i]] = true;
                    possibleMax = Math.Max(possibleMax, j + a[i]);
                }
            }
        }

        Array.Reverse(a);
        Console.WriteLine(lowerBound(a, answerLowest));
    }
    
    public int lowerBound(int[] a, int k) {
        int n = a.Length;
        if (a[0] >= k) {
            return 0;
        }
        int l = 0;
        int r = n;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (a[mid] < k) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return r;
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