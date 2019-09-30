using System;
using System.Collections.Generic;
using System.Linq;

public class Hello
{
    public static void Main()
    {
        var dic = new Dictionary<int, uint>();

        Console.ReadLine();
        for (int c = Console.Read(); c != -1; c = Console.Read())
        {
            if (c < 'a' || c > 'z')
                continue;
            uint count;
            dic.TryGetValue(c, out count);
            dic[c] = count + 1;
        }

        Console.WriteLine(
                (dic.Values.Aggregate(1ul, (s, v) => (s * (v + 1)) % 1000000007ul) - 1)
                    % (1000000007ul)
            );
    }
}