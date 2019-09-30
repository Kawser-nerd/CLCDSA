using System;
using System.Collections.Generic;
using System.Linq;

class MainClass
{
    public static void Main()
    {
        var str = Console.ReadLine()
            .Split(' ')
            .Select(x => int.Parse(x))
            .ToArray();
        var nn = str[0];
        var m = str[1];
        var ls = new List<Cake>();
        for (int i = 0; i < nn; i++)
        {
            var st = Console.ReadLine()
                .Split(' ')
                .Select(x => long.Parse(x))
                .ToArray();
            var c = new Cake() { Kireisa = st[0], Oishisa = st[1], Ninkido = st[2] };
            ls.Add(c);
        }

        var bits = CreateBits(3);

        var lss = new List<UnkoList<Cake>>();
        foreach (var item in bits)
        {
            long count = 0;
            long num = 0;
            var oti = new UnkoList<Cake>();
            ls.OrderByDescending(x =>
            {
                num = item[0] ? x.Kireisa : -x.Kireisa;
                num += item[1] ? x.Ninkido : -x.Ninkido;
                num += item[2] ? x.Oishisa : -x.Oishisa;
                return num;
            })
            .Take(m)
            .ToList()
            .ForEach(x =>
            {
                oti.Add(x);
            });
            oti.ForEach(x =>
            {
                oti.Num += item[0] ? x.Kireisa : -x.Kireisa;
                oti.Num += item[1] ? x.Ninkido : -x.Ninkido;
                oti.Num += item[2] ? x.Oishisa : -x.Oishisa;
            });
            lss.Add(oti);
        }
        var xx = lss.OrderByDescending(x => x.Num).FirstOrDefault();
        Console.WriteLine(xx.Num);
        Console.ReadLine();
    }

    class Cake
    {
        public long Kireisa;
        public long Oishisa;
        public long Ninkido;
    }

    #region?bit???
    /// <summary>
    /// Bit??????????
    /// </summary>
    /// <param name="len">???????(len?0???????)</param>
    /// <returns>?????</returns>
    public static List<List<bool>> CreateBits(int len)
    {
        return CreateBitsPri(new List<List<bool>>(), len, 0);
    }

    private static List<List<bool>> CreateBitsPri(List<List<bool>> bits, int len, int count)
    {
        if (count == 0)
        {
            var lss = new List<bool>();
            lss.Add(true);
            bits.Add(lss);
            var lx = new List<bool>();
            lx.Add(false);
            bits.Add(lx);
            count++;
            return CreateBitsPri(bits, len, count);
        }
        if (len - count == 0)
            return bits;
        count++;
        var ls = new List<List<bool>>();
        foreach (var item in bits)
        {
            var x = item.ToList();
            x.Add(true);
            item.Add(false);
            ls.Add(item);
            ls.Add(x);
        }
        return CreateBitsPri(ls, len, count);
    }
    #endregion

    class UnkoList<T> : List<T> 
    {
        public long Num;
    }
}