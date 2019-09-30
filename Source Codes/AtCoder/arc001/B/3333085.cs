using System;
using System.Linq;

public class atCoderConsole
{
    public static void Main()
    {
        // 1??????
        int number = int.Parse(Console.ReadLine());

        // 2?????
        string answers = Console.ReadLine();

        // ??1????????????4?????????
        int[] points = new int[4];

        // ????????????
        for (int i = 0; i < answers.Length; i++)
        {
            char check = answers[i];

            if (check == '1')
            {
                points[0]++;
            }
            if (check == '2')
            {
                points[1]++;
            }
            if (check == '3')
            {
                points[2]++;
            }
            if (check == '4')
            {
                points[3]++;
            }
        }

        // ?????????????????????????
        int max = points.Max();
        int min = points.Min();

        // ???????????????????????
        string output = max + " " + min;

        // ???????
        Console.WriteLine(output);
    }
}