using System;

namespace ABC090
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] hoge = Read().Split(' ');
            var a = int.Parse(hoge[0]);
            var b = int.Parse(hoge[1]);
            var cnt = 0;
            for(int i = a; i <= b; i++)
            {
                var str = i.ToString();
                if (str[0] == str[4] && str[1] == str[3]) cnt++;
            }


            Console.WriteLine(cnt);
         }

        public static string Read() { return Console.ReadLine(); }
    }
}