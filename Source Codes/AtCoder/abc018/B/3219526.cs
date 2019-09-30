using System;

class Program
{
    static void Main(string[] args)
    {
        var str = Console.ReadLine();
        var num = Convert.ToInt32(Console.ReadLine());
        for(var i = 0; i < num; i++)
        {
            var input = Console.ReadLine().Split(' ');
            var first=Convert.ToInt32(input[0]);
            var last=Convert.ToInt32(input[1]);
            for (var j = 0; j < str.Length; j++)
            {
                if (j >= first && j <Math.Ceiling((double)(last + first) / 2))
                {
                    var s = str[last - (j - first) - 1];
                        str =
                            str.Substring(0, j - 1) + s +
                            str.Substring(j,last+first-2*j-1) + str[j - 1] + str.Substring(last - (j - first));
                }
            }
        }

        Console.WriteLine(str);
    }
}