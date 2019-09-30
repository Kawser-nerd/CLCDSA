using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AGC032
{
    class V
    {
        public int Id;
        public List<V> cnctList = new List<V>();

        public V(int id)
        {
            Id = id;
        }
    }

    class B032
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());

            List<V> vlist = new List<V>();
            V v1 = new V(1); V v2 = new V(2); V v3 = new V(3);
            vlist.Add(v1);vlist.Add(v2);vlist.Add(v3);
            v1.cnctList.Add(v3); v2.cnctList.Add(v3);
            v3.cnctList.Add(v1); v3.cnctList.Add(v2);

            int m = 2;
            int i = 4;
            while (i <= N)
            {
                if (i % 2 == 0)
                {
                    foreach (V v in vlist)
                    {
                        v.Id++;
                    }
                    V vn = new V(1);
                    foreach (V v in vlist)
                    {
                        if (v.Id != i)
                        {
                            vn.cnctList.Add(v);
                            v.cnctList.Add(vn);
                            m++;
                        }
                    }
                    vlist.Add(vn);
                }
                else
                {
                    V vn = new V(i);
                    foreach (V v in vlist)
                    {
                        vn.cnctList.Add(v);
                        v.cnctList.Add(vn);
                        m++;
                    }
                    vlist.Add(vn);
                }
                i++;
            }

            vlist = vlist.OrderBy(x => x.Id).ToList();

            Console.WriteLine(m);
            foreach(V v in vlist)
            {
                foreach(V vc in v.cnctList)
                {
                    if (vc.Id > v.Id)
                    {
                        Console.WriteLine(v.Id + " " + vc.Id);
                    }
                }
            }


        }

    }
}