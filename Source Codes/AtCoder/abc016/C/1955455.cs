using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] nm = Console.ReadLine().Split().Select(int.Parse).ToArray();
        List<int>[] user = Enumerable.Range(1,nm[0]).Select(_ => new List<int>()).ToArray();
        for (int i = 0; i < nm[1]; i++)
        {
            int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
            user[a[0] - 1].Add(a[1] - 1);
            user[a[1] - 1].Add(a[0] - 1);
        }
        for (int i = 0; i < nm[0]; i++)
        {
            List<int> friendfriend = new List<int>();
            foreach (var u in user[i])
            {
                friendfriend.AddRange(user[u]);
            }
            friendfriend = friendfriend.Distinct().Where(x => !user[i].Contains(x) && x != i).ToList();
            Console.WriteLine(friendfriend.Count());
        }
    }
}