using System;

class Program
{
    static void Main()
    {
        string a = Console.ReadLine();
        int count = 0;
        int max = 0;
        for(int i = 0; i < a.Length; i++)
        {
            if ("ATGC".IndexOf(a[i])>-1)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            if (max<count)
            {
                max = count;
            }
        }
        Console.WriteLine(max);
    }
}