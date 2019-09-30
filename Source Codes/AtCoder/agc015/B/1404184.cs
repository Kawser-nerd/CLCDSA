using System;

class program
{
    static void Main(string[] args)
    {
        //U??????????????????????
        string input = Console.ReadLine();
        long ans = 0;

        for(int i = 0; i < input.Length; i++)
        {
            if (input[i] == 'U')
            {
                ans += (input.Length - (i + 1)) * 1 + i * 2;
            }else
            {
                ans += (input.Length - (i + 1)) * 2 + i * 1;
            }
        }

        Console.WriteLine(ans);
           
    }
}