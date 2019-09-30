using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

class Program
{
    bool x(char a)
    {
        return a == 'X' || a == 'T';
    }
    bool o(char a)
    {
        return a == 'O' || a == 'T';
    }
    int  chk(char a, char b, char c, char d)
    {
        if (x(a) && x(b) && x(c) && x(d)) return 1;
        if (o(a) && o(b) && o(c) && o(d)) return 2;
        return 0;
    }
    void Run()
    {
        StreamReader sr = new StreamReader(@"D:\Temporary Files\Mary's HDrive\G-remain-backup\Contest 2013\GCJ\Q\a.in");
        int _ = Convert.ToInt32(sr.ReadLine());
        for (int t = 1; t <= _; t++)
        {
            char[][] str = new char[4][];
            bool nonempty = false;
            int mask = 0;
            for (int i = 0; i < 4; i++)
            {
                str[i] = sr.ReadLine().ToCharArray();
                foreach (char p in str[i])
                    if (p == '.')
                        nonempty = true;
            }
            sr.ReadLine();
            Console.Write("Case #{0}: ", t);
            for (int i = 0; i < 4; i++)
            {
                mask |= chk(str[i][0], str[i][1], str[i][2], str[i][3]);
                mask |= chk(str[0][i], str[1][i], str[2][i], str[3][i]);
            }
            mask |= chk(str[0][0], str[1][1], str[2][2], str[3][3]);
            mask |= chk(str[0][3], str[1][2], str[2][1], str[3][0]);
            if (mask == 1)
                Console.WriteLine("X won");
            else
                if (mask == 2)
                    Console.WriteLine("O won");
                else
                    if (nonempty)
                        Console.WriteLine("Game has not completed");
                    else
                        Console.WriteLine("Draw");
        }
    }
    static void Main(string[] args)
    {
        new Program().Run();
    }
}