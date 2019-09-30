using System;
using System.Collections;
using System.Linq;
namespace AGC013A
{
    class Program
    {
        static void ShowAL(ArrayList al)
        {
            for (int i = 0; i < al.Count; i++)
                Console.Write("{0} ", (int)al[i]);
            Console.WriteLine();
        }
        static int Main()
        {
            int n = int.Parse(Console.ReadLine());
            int[] a = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int ans = 0;
            ArrayList al = new ArrayList();
            for (int i = 0; i < n - 1; i++)
                if (a[i] != a[i + 1])
                    al.Add(a[i]);
            al.Add(a[n - 1]);
            //ShowAL(al);
            a = (int[])al.ToArray(typeof(int));
            al = new ArrayList();
            for (int i = 0; i < a.Length; i++)
            {
                if (al.Count < 2)
                {
                    al.Add(a[i]);
                    continue;
                }
                if ((int)al[al.Count - 2] < (int)al[al.Count - 1] && (int)al[al.Count - 1] > a[i])
                {
                    ans++;
                    //ShowAL(al);
                    al = new ArrayList();
                    al.Add(a[i]);
                    continue;
                }
                if ((int)al[al.Count - 2] > (int)al[al.Count - 1] && (int)al[al.Count - 1] < a[i])
                {
                    ans++;
                    //ShowAL(al);
                    al = new ArrayList();
                    al.Add(a[i]);
                    continue;
                }
                al.Add(a[i]);
            }
            //ShowAL(al);
            ans++;
            Console.WriteLine(ans);
            return 0;
        }
    }
}