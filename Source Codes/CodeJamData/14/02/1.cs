using System;
using System.Collections.Generic;
using System.Linq;

class Myon
{
    public Myon() { }
    public static void Main()
    {
        new Myon().run2();
    }

    Scanner cin;
    public void run2()
    {
        cin = new Scanner();
        int T = cin.nextInt();
        for (int i = 0; i < T; i++)
        {
            Console.Write("Case #{0}: ", i + 1);
            //Console.WriteLine("Case #{0}:", T + 1);

            run();
        }
    }

    void run()
    {
        double C = cin.nextDouble();
        double F = cin.nextDouble();
        double X = cin.nextDouble();
        double best = X / 2;
        double now = 0;
        double speed = 2;
        while (true)
        {
            now += C / speed;
            speed += F;
            double next = now + X / speed;
            if (next > best) break;
            best = next;

        }
        Console.WriteLine("{0:0.000000000000000}", best);
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
        if (i < s.Length) return s[i++];
        s = Console.ReadLine().Split(cs, StringSplitOptions.RemoveEmptyEntries);
        i = 0;
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
