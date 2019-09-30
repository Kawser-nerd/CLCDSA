using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
    static void Main()
    {
        var nm = Console.ReadLine().Split().Select(x => long.Parse(x)).ToArray();
        var abArray = new List<long[]>();
        for (int i = 0; i < nm[0]; i++)
        {
            abArray.Add(Console.ReadLine().Split().Select(x => long.Parse(x)).ToArray());
        }

        abArray.Sort((a,b) => (int)(a[0] - b[0]));

        long price = 0;
        var need = nm[1];
        for (int i = 0; i < nm[0]; i++)
        {
            if (abArray[i][1] > need)
            {
                price += need * abArray[i][0];
                need = 0;
            }
            else
            {
                price += abArray[i][1] * abArray[i][0];
                need -= abArray[i][1];
            }

            if (need == 0)
            {
                Console.WriteLine(price);
                break;
            }
        }
    }
}