using System;
 
class Solver {
    public Solver() {}
    public static int Main() {
        new Solver().solve();
        return 0;
    }
 
    public void solve() {
        long x;
        x = long.Parse(Console.ReadLine());
        int ans = (int)(Math.Ceiling(Math.Sqrt(2 * x + 0.25) - 0.5));
        Console.WriteLine(ans);
    }
}