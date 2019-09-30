using System;
class Program
{
    static void Main(string[] args)
    {
        int iSum = 0;
        for (int i = 0; i < 3; i++)
        {
            string[] sInp = Console.ReadLine().Trim().Split(' ');
            iSum += int.Parse(sInp[0]) * int.Parse(sInp[1]) / 10;
        }
        Console.WriteLine("{0}", iSum.ToString());
    }
}