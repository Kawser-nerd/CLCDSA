using System;

namespace atcoderB
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            string s = Console.ReadLine();
            char data = s[0];
            int count = 0;
            string ans = "";
            for(int i = 0; i < s.Length; i++)
            {
                if (s[i] == data)
                {
                    count++;
                }
                else
                {
                    ans += data + count.ToString();
                    data = s[i];
                    count = 1;
                }
            }
            Console.WriteLine(ans+data+count.ToString());
        }
    }
}