using System;

class Program
{
    static void Main(string[] args)
    {
        var num = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine(
            string.Format("{0:d2}:{1:d2}:{2:d2}", num / 3600, (num - (num / 3600)*3600) / 60, num - (num / 3600)*3600- ((num - (num / 3600) * 3600) / 60)*60));
    }
}