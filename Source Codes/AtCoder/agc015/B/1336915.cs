using System;
class MyMain
{
    static void Main()
    {
        string s = System.Console.ReadLine().Trim();
        long count=0;
        for (int i = 0; i < s.Length;i++ )
        {
                if (s[i] == 'U') count += ((s.Length - i) - 1) + i * 2;
                else count += i + ((s.Length - i) - 1) * 2;
                //if (s[i] == 'U') count += s.Length + i - 1;
                //else count += 2*(s.Length- 1) -i;
        }
        System.Console.WriteLine(count);
        System.Console.ReadLine();
    }
}