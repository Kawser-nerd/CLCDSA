using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

public class Hello
{

    public static string[] table;
    public static string[] numbers;

    public static void Main()
    {
        table = Console.ReadLine().Split(' ');
        int num = int.Parse(Console.ReadLine());
        Dictionary<string, string> dict = new Dictionary<string, string>();

        numbers = new string[num];
        string str = "";
        string temp = "";
        long[] numLong = new long[num];

        for(int i = 0; i < num; i++)
        {
            numbers[i] = Console.ReadLine();
            for(int j = 0; j < numbers[i].Length; j++)
            {
                temp = numbers[i];
                str += Array.IndexOf(table, numbers[i][j].ToString());  
            }
            try
            {
                dict.Add(str, temp);
            }
            catch(ArgumentException)
            {

            }
            numLong[i] = long.Parse(str);
            str = "";
        }

        Array.Sort(numLong);

        foreach(long s in numLong)
        {
            Console.WriteLine(dict[s.ToString()]);
        }
    }
}