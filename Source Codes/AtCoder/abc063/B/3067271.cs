using System;

namespace Sample101
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = Console.ReadLine();
            string result = "yes";
            char[] strArray = str.ToCharArray();

            for (int i = 0; i < strArray.Length; ++i)
            {
                for (int j = i + 1; j < strArray.Length; ++j)
                {
                    if (strArray[i] == strArray[j])
                    {
                        result = "no";
                        break;
                    }
                }
                if (result.Equals("no"))
                {
                    break;
                }
            }
            Console.WriteLine(result);
        }
    }
}