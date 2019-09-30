using System;

namespace arc065_a
{
    class Program
    {
        static void Main(string[] args)
        {
            char[] a = Console.ReadLine().ToCharArray();
            Array.Reverse(a);
            string s = new string(a);
            bool ret = true;
            while (s.Length != 0 && ret)
            {
                string x = s.Substring(0, 5);
                if (x == "maerd") s = s.Substring(5, s.Length - 5);
                else if (x == "esare") s = s.Substring(5, s.Length - 5);
                else if (x + s[5] == "resare") s = s.Substring(6, s.Length - 6);
                else if (x + s[5] + s[6] == "remaerd") s = s.Substring(7, s.Length - 7);
                else ret = false;
            }
            Console.WriteLine(ret ? "YES" : "NO");
        }
    }
}