using System;
using System.Text;

    class Program
    {        static void Main(string[] args)
        {
            var S = Console.ReadLine();
            var tmp = new StringBuilder();
            var maerd = new StringBuilder("maerd");
            var remaerd = new StringBuilder("remaerd");
            var esare = new StringBuilder("esare");
            var resare = new StringBuilder("resare");
            for (var i = S.Length-1;0<=i;i--)
            {
                tmp.Append(S[i]);
                if (tmp.Length < 5) continue;
                if (tmp.Equals(maerd)) tmp.Clear(); 
                if (tmp.Equals(remaerd)) tmp.Clear(); 
                if (tmp.Equals(esare)) tmp.Clear(); 
                if (tmp.Equals(resare)) tmp.Clear(); 
            }
            if (tmp.Length!=0)
            {
                Console.WriteLine("NO");
                return;
            }
            Console.WriteLine("YES");
        }
    }