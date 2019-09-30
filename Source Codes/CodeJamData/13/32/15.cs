using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

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
        s = Console.ReadLine().Split(cs); //, StringSplitOptions.RemoveEmptyEntries);
        i = 0;
        return s[i++];
    }

    public double nextDouble()
    {
        return double.Parse(next());
    }

    public int nextInt()
    {
        return int.Parse(next());
    }

    public long nextLong()
    {
        return long.Parse(next());
    }
}

class Solver
{
    Scanner cin;

    int[] powers= new int[1001];

    void SolveAll()
    {
        for (int i = 1; i <= 1000; i++)
            powers[i] = i * i;

        cin = new Scanner();
        int T = cin.nextInt();
        for (int c = 1; c <= T; c++)
        {
            Console.Write("Case #{0}: ", c);
            SolveCase(c, T);
            Console.Out.Flush();
        }
    }

    public static void Main()
    {
        Console.SetIn(new StreamReader("bs.in"));
        Console.SetOut(new StreamWriter("bs.out"));
        (new Solver()).SolveAll();
    }

    void SolveCase(int c, int T)
    {
        int x = cin.nextInt();
        int y = cin.nextInt();
        int yorg = y;
        int xorg = x;

        y = Math.Abs(y);
        x = Math.Abs(x);

        char[] steps = new char[500];
        int nsteps = 0;

        int posx = 0;
        int posy = 0;

        while (posy < y)
        {
            steps[nsteps] = (yorg > 0 ? 'N' : 'S');
            nsteps++;
            posy += nsteps;
        }

        if (posy > y)
        {
            int diff = posy - y;
            if (diff == 1)
            {
                steps[nsteps] = (yorg > 0 ? 'N' : 'S');
                nsteps++;
                steps[nsteps] = (yorg > 0 ? 'S' : 'N');
                nsteps++;
            }
            else
            {
                steps[diff / 2 - 1] = (yorg > 0 ? 'S' : 'N');
                if (diff % 2 != 0)
                {
                    steps[nsteps] = (yorg > 0 ? 'N' : 'S');
                    nsteps++;
                    steps[nsteps] = (yorg > 0 ? 'S' : 'N');
                    nsteps++;
                }
            }
        }

        while (posx < x)
        {
            steps[nsteps] = (xorg > 0 ? 'E' : 'W');
            nsteps++;
            posx += nsteps;
        }

        while (posx != x)
        {
            steps[nsteps] = (xorg > 0 ? 'E' : 'W');
            nsteps++;
            steps[nsteps] = (xorg > 0 ? 'W' : 'E');
            nsteps++;
            posx--;
        }

        steps[nsteps] = '\0';
        Console.WriteLine(new string(steps, 0, nsteps));
    }
}

