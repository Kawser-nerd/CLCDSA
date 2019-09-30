using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace test.Google
{
    public class SaveUniverse
    {
        public static void Main(string[] arg)
        {
            try
            {
                using (StreamReader sr = new StreamReader(arg[0]))
                using (StreamWriter sw = new StreamWriter(arg[1]))
                {
                    int num = int.Parse(sr.ReadLine());
                    for (int i = 0; i < num; ++i)
                    {
                        int numEngine = int.Parse(sr.ReadLine());
                        Dictionary<string, int> dict = new Dictionary<string, int>();
                        for (int k = 0; k < numEngine; ++k) dict[sr.ReadLine()] = k;

                        int numSearch = int.Parse(sr.ReadLine());
                        int[] searches=new int[numSearch];
                        for (int k = 0; k < numSearch; ++k) searches[k] = dict[sr.ReadLine()];

                        //string input=sr.ReadLine();
                        //string output = Convert(input.Split(' '));
                        //Console.WriteLine(input + "=" + output);
                        int switches = Get(numEngine, searches);
                        sw.WriteLine("Case #" + (i + 1) + ": " + switches);
                    }
                }
            }
            catch (Exception e) { Console.WriteLine(e.Message + e.StackTrace); }
            Console.ReadKey();
        }


        public static int Get(int numEngine, int[] searches) 
        {
            int res = 0;

            int len = searches.Length;
            for (int i = 0; i < len;)
            {
                int max = i;
                for (int j = 0; j < numEngine; ++j)
                {
                    int t = i;
                    while (t < len && searches[t] != j) t++;
                    if (t > max) max = t;
                }

                i = max;
                if (i<len)res++;
            }

            return res;
        }
    }
}
