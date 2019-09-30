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
        int[] num = new int[16];
        for (int t = 0; t < 2; t++)
        {
            int target = cin.nextInt() - 1;
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    int a = cin.nextInt() - 1;
                    if (target == i) num[a]++;
                }
            }
        }
        int count = num.Count(x => (x == 2));
        if (count == 0)
        {
            Console.WriteLine("Volunteer cheated!");
        }
        else if(count>=2){
            Console.WriteLine("Bad magician!");
        }
        else
        {
            for (int i = 0; i < num.Length; i++)
            {
                if (num[i] == 2) Console.WriteLine(i+1);
            }
        }
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
