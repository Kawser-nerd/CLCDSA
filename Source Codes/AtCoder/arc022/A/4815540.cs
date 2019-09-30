using System;
using System.Linq;
class Program
{
    static void Main()
    {
        string input = Console.ReadLine().ToUpper();
        int count = 0;
        string ict = "ICT";
        for (int a = 0; a < input.Length; a++)
        {
            if (input[a]==ict[count])
            {
                count++;
            }
            if (count == 3) break;
        }
        Console.WriteLine(count==3?"YES":"NO");
        Console.ReadLine();
    }
}