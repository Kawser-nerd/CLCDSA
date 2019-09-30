using System;
using System.Linq;

class Program {
    static void Main(string[] args) {
        //? ?
        int x = cin.ni() + 100;
        int y = cin.ni() + 100;
        int r = cin.ni();

        //?????
        int left = cin.ni() + 100;
        int top = cin.ni() + 100;
        int right = cin.ni() + 100;
        int bottom = cin.ni() + 100;

        Console.WriteLine(
             x - r < left ||
             y - r < top ||
             x + r > right ||
             y + r > bottom ? "YES" : "NO");


        Console.WriteLine(
           pitag(x, y, left, top) > r ||
           pitag(x, y, left, bottom) > r ||
           pitag(x, y, right, top) > r ||
           pitag(x, y, right, bottom) > r ? "YES" : "NO");

    }
    private static double pitag(int x1, int y1, int x2, int y2) {
        return Math.Sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }
}


public class cin {
    private static string[] s = new string[0];
    private static int i = 0;

    private static char[] cs = new char[] { ' ' };

    public static string next() {
        if (i < s.Length) return s[i++];
        string st = Console.ReadLine();
        while (st == "") st = Console.ReadLine();
        s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
        i = 0;
        return next();
    }

    public static int ni() {
        return int.Parse(next());
    }

    public static long nextLong() {
        return long.Parse(next());
    }

    public static double nextDouble() {
        return double.Parse(next());
    }

}