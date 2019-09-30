using System;
class Program
{
    static void Main()
    {
        var nm = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        var map = new string[nm[0]];
        var temp = new string[nm[1]];
        for (int i = 0; i < nm[0]; i++) map[i] = Console.ReadLine();
        for (int i = 0; i < nm[1]; i++) temp[i] = Console.ReadLine();
        bool yes = true;
        bool ans = false;
        for (int x = 0; x < nm[0] - nm[1] + 1; x++)
        {
            for (int y = 0; y < nm[0] - nm[1] + 1; y++)
            {
                for (int i = 0; i < nm[1]; i++)
                {
                    for (int j = 0; j < nm[1]; j++)
                    {
                        if (map[x + i][y + j] != temp[i][j]) yes = false;
                    }
                }
                if (yes) ans = true;
                else yes = true;
            }
        }
        Console.WriteLine(ans ? "Yes" : "No");
    }
}