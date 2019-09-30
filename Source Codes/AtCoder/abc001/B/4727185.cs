using System;

class Program
{
    static void Main()
    {
        var input = int.Parse(Console.ReadLine());
        var VV = string.Empty;

        if(input < 100)
        {
            VV = "00";
        }
        else if(100 <= input && input <= 5000)
        {
            VV = ((float)input / 100).ToString("00");
        }
        else if(6000 <= input && input <= 30000)
        {
            VV = ((float)input / 1000 + 50).ToString();
        }
        else if(35000 <= input && input <= 70000)
        {
            VV = (((float)input / 1000 - 30) / 5 + 80).ToString();
        }
        else if(input > 70000)
        {
            VV = "89";
        }
        Console.WriteLine(VV);
    }
}