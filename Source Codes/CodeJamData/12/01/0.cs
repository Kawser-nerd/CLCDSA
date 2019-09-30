using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class A
{
    public static void Main()
    {
        string a = "abcdefghijklmnopqrstuvwxyz ";
        string b = "yhesocvxduiglbkrztnwjpfmaq ";

        int T = ReadInt();
        for (int i = 1; i <= T; i++)
        {
            string line = ReadLine();
            line = new string(line.Select(c => b[a.IndexOf(c)]).ToArray());
            Console.WriteLine("Case #{0}: {1}", i, line);
        }
    }

    #region Library

    static string ReadLine()
    {
        return Console.ReadLine();
    }

    static string[] ReadWords()
    {
        return ReadLine().Split();
    }

    static int ReadInt()
    {
        return int.Parse(ReadLine());
    }

    static int[] ReadInts()
    {
        return Array.ConvertAll(ReadWords(), int.Parse);
    }

    #endregion
}
