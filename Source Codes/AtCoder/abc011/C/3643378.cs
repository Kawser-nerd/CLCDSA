using System;

namespace Atcoder
{
    class Progtam
    {
        static string ans;
        public static void Main(string[] arg)
        {
            Solve();
            Console.WriteLine(ans);
     //       Console.ReadLine();
        }
        static void Solve()
        {
            int n = int.Parse(Console.ReadLine());
            int[] ng=new int[3];
            
            for (int i = 0; i < 3; i++)
            {
                ng[i] = int.Parse(Console.ReadLine());
            }
            

            if (ng[0] == n || ng[1] == n || ng[2] == n) { ans = "NO"; return; }
            Array.Sort(ng);
            for (int i = 0; i < 100; i++)
            { 
                if ((n - 3) != ng[2] && (n - 3) != ng[1] && (n - 3) != ng[0]) { n -= 3; }
                else if ((n - 2) != ng[2] && (n - 2) != ng[1] && (n - 2) != ng[0]) { n -= 2; }
                else if ((n - 1) != ng[2] && (n - 1) != ng[1] && (n - 1) != ng[0]) { n -= 1; }
                else { ans = "NO";return; }
            }
            if (n <= 0) ans = "YES";
            else ans = "NO";


        }
    }
}