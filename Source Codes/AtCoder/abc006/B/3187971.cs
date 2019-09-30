using System;

class Program
{
    static void Main(string[] args)
    {
        var num = Convert.ToInt32(Console.ReadLine());
        var toriboti = new int[num];
        toriboti[0] = 0;
        if(num>=2)
        toriboti[1] = 0;
        if(num>=3)
        toriboti[2] = 1;
        if (num >= 4)
        {
            for (var i = 3; i < num; i++)
            {
                toriboti[i] = (toriboti[i - 1] + toriboti[i - 2] + toriboti[i - 3]) % 10007;
            }
        }
        Console.WriteLine(toriboti[num - 1]);
    }
}