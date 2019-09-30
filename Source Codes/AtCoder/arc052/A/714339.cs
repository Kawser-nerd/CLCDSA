using System;
using System.Collections.Generic;
namespace ARC052
{
    class Problem
    {

        public static List<string[]> getinputdata()
        {

            List<string[]> list_temp = new List<string[]>();
            string strdata = Console.ReadLine();

            while (strdata != null)
            {

                string[] s_temp = strdata.Split(' ');

                list_temp.Add(s_temp);

                strdata = Console.ReadLine();

            }

            return list_temp;
        }


        public static void Main(string[] args)
        {
            List<string[]> list_result = new List<string[]>();
            list_result = getinputdata();

            string s = list_result[0][0];

            string ans = "";

            for(int i = 0; i<s.Length; i++)
            {

                if (char.IsNumber(s[i]))
                {
                    //Console.WriteLine(s[i] + "=number");

                    ans = ans + s[i].ToString();
                    
                }
          


            }

            Console.WriteLine(ans);

        }
    }
}