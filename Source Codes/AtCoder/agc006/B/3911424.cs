using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
{
    public Program() { }


    Scanner cin;

    long[] All;
    long[] Pate;

    void myon()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        int x = cin.nextInt();

        if(x == 1 || x == 2 * N - 1)
        {
            Console.WriteLine("No");
            return;
        }

        Console.WriteLine("Yes");

        int step = 1;
        for (int i = 0; i < N - 2; i++)
        {
            while (step >= x - 1 && step <= x + 1) { step++; }
            Console.Write(step + " ");
            step++;
        }
        Console.Write((x - 1) + " ");
        Console.Write((x - 0) + " ");
        Console.Write((x + 1) + " ");

        for (int i = 0; i < N - 2; i++)
        {
            while (step >= x - 1 && step <= x + 1) { step++; }
            Console.Write(step + " ");
            step++;
        }
    }

    static void Main(string[] args)
    {
        new Program().myon();
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
        string st = Console.ReadLine();
        while (st == "") st = Console.ReadLine();
        s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
        i = 0;
        return next();
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