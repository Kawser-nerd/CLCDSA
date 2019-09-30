using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;

static class MainClass
{
    public static void Main()
    {
        int[] dx = { 0, 0, 1, -1 };
        int[] dy = { -1, 1, 0, 0 };
        var unti = new bool[10, 10];
        var fs = true;
        KeyValuePair<int, int> first = new KeyValuePair<int, int>();
        var fuchiLs = new List<KeyValuePair<int, int>>();
        for (int i = 0; i < 10; i++)
        {
            var count = 0;
            Console.ReadLine()
                .ToList()
                .ForEach(x =>
                {
                    var ti = x == 'o';
                    unti[i, count] = ti;
                    if (fs && ti)
                    {
                        first = new KeyValuePair<int, int>(i, count);
                        fs = false;
                    }
                    count++;
                });
        }
        bool isCan = false;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (unti[i, j])
                    continue;
                var iss = unti.DeepClone();
                iss[i, j] = true;
                var stk = new Stack<KeyValuePair<int, int>>();
                stk.Push(first);
                KeyValuePair<int, int> item;
                while (true)
                {
                    try
                    {
                        item = stk.Pop();
                    }
                    catch { break; }
                    for (int k = 0; k < 4; k++)
                    {
                        var xxx = item.Key + dx[k];
                        var yyy = item.Value + dy[k];
                        if (xxx < 0 || yyy < 0 || xxx >= 10 || yyy >= 10)
                            continue;
                        if (iss[xxx, yyy])
                        {
                            stk.Push(new KeyValuePair<int, int>(xxx, yyy));
                        }
                    }
                    iss[item.Key, item.Value] = false;
                }
                bool isOk = true;

                foreach (var items in iss)
                {
                    if (items)
                    {
                        isOk = false;
                        break;
                    }
                }
                if (isOk)
                {
                    isCan = true;
                    break;
                }
            }
            if (isCan)
                break;
        }
        Console.WriteLine(isCan ? "YES" : "NO");
        Console.ReadLine();
    }
    public static T DeepClone<T>(this T src)
    {
        using (var memoryStream = new MemoryStream())
        {
            var binaryFormatter
              = new BinaryFormatter();
            binaryFormatter.Serialize(memoryStream, src);
            memoryStream.Seek(0, SeekOrigin.Begin);
            return (T)binaryFormatter.Deserialize(memoryStream);
        }
    }
}