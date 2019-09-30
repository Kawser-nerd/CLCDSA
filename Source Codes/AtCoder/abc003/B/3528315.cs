using System;

namespace AtCoderConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            // ??????1????
            string inputS = Console.ReadLine();
            string inputT = Console.ReadLine();

            // char???????????
            for(int i = 0; i < inputS.Length; i++)
            {
                if(!check(inputS, inputT, i))
                {
                    Console.WriteLine("You will lose");
                    return;
                }
            }

            // ???????
            Console.WriteLine("You can win");
        }

        // ?????@??????
        public static bool check(string s, string t, int n)
        {
            if (s[n] == t[n] ||
                (s[n] == '@' && (t[n] == '@' || t[n] == 'a' || t[n] == 't' || t[n] == 'c' || t[n] == 'o' || t[n] == 'd' || t[n] == 'e' || t[n] == 'r')) ||
                (t[n] == '@' && (s[n] == '@' || s[n] == 'a' || s[n] == 't' || s[n] == 'c' || s[n] == 'o' || s[n] == 'd' || s[n] == 'e' || s[n] == 'r')))
                return true;
            else return false;
        }
    }
}