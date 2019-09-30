using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program
{
    static void Main(string[] args)
    {
        var str = ReadLine();
        HashSet<char> charHash = new HashSet<char>();
        bool end = false;
        var current = 'a';
        foreach (var item in str)
        {
            charHash.Add(item);
        }
        for (int i = current; i < 'a' + 26; i++)
        {
            if (!charHash.Any(x => x == (char)i))
            {
                WriteLine(str + ((char)i).ToString());
                end = true;
                return;
            }
        }
        while (!end)
        {
            charHash.Clear();
            foreach (var item in str)
            {
                charHash.Add(item);
            }
            for (int i = current+1; i < 'a' + 26; i++)
            {
                if (!charHash.Any(x => x == (char)i))
                {
                    WriteLine(str.Substring(0, str.Length-1) + ((char)i).ToString());
                    end = true;
                    return;
                }
            }
            str = str.Substring(0,str.Length-1);
            if(str == "")
            {
                WriteLine("-1");
                end = true;
                return;
            }
            current = str.Last();
        }
    }
}