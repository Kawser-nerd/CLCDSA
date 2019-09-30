using System;
class A
{
    static void Main()
    {
        string a = Console.ReadLine();
        for (int i = 0; i < a.Length; i++)
        {
            string y = a.Substring(i, 1); string u = "";
            if (i < a.Length - 1)
            {//string
                u = a.Substring(i + 1, 1);
            }
            if (y == "1" || y == "2" || y == "3" || y == "4" || y == "5" || y == "6" || y == "7" || y == "8" || y == "9" || y == "0")
            {//if(i<a.Length-1)
                if (u == "1" || u == "2" || u == "3" || u == "4" || u == "5" || u == "6" || u == "7" || u == "8" || u == "9" || u == "0")
                {
                    Console.Write(int.Parse(u) + 10 * int.Parse(y)); break;
                }
                else { Console.WriteLine(int.Parse(y)); break; }

            }
        }


    }
}