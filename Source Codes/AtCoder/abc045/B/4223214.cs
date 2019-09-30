using System;

class quiz
{
    public char solve(string Sa, string Sb, string Sc)
    {
        int ai = 0, bi = 0, ci = 0;
        char abc = 'a';

        while (true)
        {
            if(abc == 'a')
            {

                if (ai == Sa.Length)
                    return 'A';
                abc = Sa[ai];
                ai++;
            }
            else if(abc == 'b')
            {
                if (bi == Sb.Length)
                    return 'B';
                abc = Sb[bi];
                bi++;
            }
            else
            {
                if (ci == Sc.Length)
                    return 'C';
                abc = Sc[ci];
                ci++;
            }
        }
        return 'e';
    }

    public int[] ParseIntBySpace(string str)
    {
        int[] array = new int[str.Length];
        int lastloc = 0, spaceloc = -1;

        for (int i = 0; i < str.Length; i++)
        {
            if (str[i] == ' ')
            {
                array[lastloc++] = int.Parse(str.Substring(spaceloc + 1, i - spaceloc - 1));
                spaceloc = i;
            }
            else if (i == str.Length - 1)
            {
                array[lastloc++] = int.Parse(str.Substring(spaceloc + 1, i - spaceloc));
            }
        }

        Array.Resize(ref array, lastloc);

        return array;
    }
}

class Example
{
    static void Main()
    {
        quiz ex = new quiz();

        //while (true)
        //{
        Console.WriteLine(ex.solve(Console.ReadLine(), Console.ReadLine(), Console.ReadLine()));
        //}
    }
}