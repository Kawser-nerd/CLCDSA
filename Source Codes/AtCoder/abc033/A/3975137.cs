using System;

namespace Number
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            string s = Console.ReadLine();
            //string s = "aaaa";
            string hznStr = s.Substring(0, 1);

            hznStr = hznStr += hznStr += hznStr += hznStr;

            string answer = "";
      

            if (s.Length==4)
            {
                if (s.Equals(hznStr))
                {
                    answer = "SAME";
                }
                else
                {
                    answer = "DIFFERENT";
                }
            }
            else
            {
                answer = "DIFFERENT";
            }

            Console.WriteLine(answer);
        }
    }
}