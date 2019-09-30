using System;

public class Hello
{
    public static void Main()
    {
        var map = new int[4, 4];
        for (int i = 0; i < 4; i++)
        {
            string[] line = Console.ReadLine().Trim().Split(' ');
            for (int j = 0; j < 4; j++) map[i, j] = int.Parse(line[j]);
        }
        var mes = "GAMEOVER";
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 3; j++)
                if (map[i,j] == map[i,j+1]  | map[j, i] == map[j + 1, i] ) { mes = "CONTINUE";  goto end; }
        end:;
        Console.WriteLine(mes);
    }
}