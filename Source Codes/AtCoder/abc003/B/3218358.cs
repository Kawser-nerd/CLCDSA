using System;

class Program
{
    static void Main(string[] args)
    {
        var str1 = Console.ReadLine();
        var str2 = Console.ReadLine();

        var canWin = false;
        if (str1 == str2)
        {
            canWin = true; Console.WriteLine("You can win");
        }

        if (!canWin)
        {
            for (var i = 0; i < str1.Length; i++)
            {
                if (str1.Substring(i, 1) != "@" && str2.Substring(i, 1) != "@" && str1.Substring(i, 1) != str2.Substring(i, 1)) break;
                if (str1.Substring(i, 1) == "@" && !IsContainCharactor(str2.Substring(i, 1))) break;
                if(str2.Substring(i, 1) == "@" && !IsContainCharactor(str1.Substring(i, 1))) break;
                if (i == str1.Length - 1) canWin = true;
            }

            var result = canWin ? "You can win" : "You will lose";
            Console.WriteLine(result);
        }
    }

    private static bool IsContainCharactor(string s)
    {
        if (s == "a" || s == "t" || s == "c" || s == "o" || s == "d" || s == "e" || s == "r"||s=="@") return true;
        else return false;
    }
}