using System;
 
class Program
{
    static void Main()
    {
        bool flag = false;
        string[,] a = new string[4, 4];
        for (int i = 0; i < 4; i++)
        {
            string[] h = Console.ReadLine().Split();
            for (int k = 0; k < 4; k++)
            {
                a[i, k] = h[k];
                if (k != 0)
                {
                    if (a[i, k] == a[i, k - 1]) { flag = true; }
                }
            }
        }
        if (!flag)
        {
            for (int k = 0; k < 4; k++)
            {
                if (flag) { break; }
                for (int i = 1; i < 4; i++)
                {
                    if (a[i, k] == a[i-1, k ])
                    {
                        flag = true; break;
                    }
                }
            }
 
        }
        Console.WriteLine(flag ? "CONTINUE" : "GAMEOVER");
 
        Console.ReadLine();
    }
}