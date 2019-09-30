using System;

class quiz
{
    public int solve(int a, int b, int h)
    {
        return (a + b) * h / 2;
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
            Console.WriteLine(ex.solve(int.Parse(Console.ReadLine()), int.Parse(Console.ReadLine()),int.Parse(Console.ReadLine())));
        //}
    }
}