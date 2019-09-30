using System;
class Program
{
    public static void Main()
    {
        int player = 1;
        char[] sa = Console.ReadLine().ToCharArray();
        char[] sb = Console.ReadLine().ToCharArray();
        char[] sc = Console.ReadLine().ToCharArray();
        int a = 0, b = 0, c = 0;
        char s;
        for (; ; )
        {
            if (player == 1)
            {
                try
                {
                    s = sa[a];
                }
                catch (IndexOutOfRangeException)
                {
                    Console.WriteLine("A");
                    break;
                }
                a++;
            }
            else if (player == 2)
            {
                try
                {
                    s = sb[b];
                }
                catch (IndexOutOfRangeException)
                {
                    Console.WriteLine("B");
                    break;
                }
                b++;
            }
            else
            {
                try
                {
                    s = sc[c];
                }
                catch (IndexOutOfRangeException)
                {
                    Console.WriteLine("C");
                    break;
                }
                c++;
            }
            if (s == 'a')
                player = 1;
            else if (s == 'b')
                player = 2;
            else
                player = 3;
        }
    }
}