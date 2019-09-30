using System.Linq;
using System;
class A
{
    static void Main()
    {
        long a = long.Parse(Console.ReadLine());
      //  a = long.MaxValue;
        string str = a.ToString();
        bool flag = true;
        for (int i = 0; i < str.Length; i++) { if (str[i] != '9'&&i!=0) { flag = false; } }
        if (flag) { Console.WriteLine((str.Length-1) * 9+(long.Parse((str.Substring(0,1)))));Console.ReadLine(); return; }
        else {
            if (str.Length == 1) { Console.WriteLine(a);Console.ReadLine(); return; }
            Console.WriteLine((str.Length - 1) * 9 + int.Parse(str.Substring(0, 1))-1); }
        Console.ReadLine();
    }
}