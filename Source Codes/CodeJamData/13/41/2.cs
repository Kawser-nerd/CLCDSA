using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Solvers;
using GCJDevKit.Tools;
using System.Threading;

namespace GCJDevKit.Solvers
{

    class Pole
    {
        public bool isEntry; // if true, than this is input
        public int station; // which station
        public int quantity; //how many people

        public override string ToString()
        {
            return "From " + station + " ? " + isEntry + " quan " + quantity;
        }
    }

    public class A : AbstractSolver
    {
        const long PRIME = 1000002013;

        int n;
        int m;
        int[] o;
        int[] e;
        int[] p;

        protected override object Solve(System.IO.StreamReader input)
        {
            n = NextInt();
            m = NextInt();

            Pole[] pola = new Pole[2 * m];

            o = new int[m];
            e = new int[m];
            p = new int[m];

            long fair = 0;

            for (int i = 0; i < m; i++)
            {
                o[i] = NextInt();
                e[i] = NextInt();
                p[i] = NextInt();

                pola[2 * i] = new Pole() { isEntry = true, station = o[i], quantity = p[i] };
                pola[2 * i + 1] = new Pole() { isEntry = false, station = e[i], quantity = p[i] };

                fair = ( fair + price(o[i], e[i]) * p[i]) % PRIME;

            }

            Array.Sort(pola, (p1, p2) =>
            {
                if (p1.station == p2.station)
                {
                    if (p1.isEntry == p2.isEntry) return 0;
                    return p1.isEntry ? -1 : 1;
                }
                return p1.station - p2.station;
            });

            for (int i = 1; i < 6; i++)
            {
                price(1, i);
            }

            long r = ( PRIME + fair -  calcCheaters(pola)  ) % PRIME;

            return r;
        }

        long price(long from, long to)
        {
            return price(to - from);
        }

        long price(long len)
        {
            if (len == 0) return 0;
            
            return (PRIME + len * n - len * (len - 1) / 2) % PRIME;
        }

        long calcCheaters(Pole[] pola)
        {
            Dictionary<int, long> passangers = new Dictionary<int, long>(); //how many passangers from key station.

            long totalPricePaid = 0;
            List<int> keys  = new List<int>();

            foreach (var pole in pola)
            {
                if (pole.isEntry)
                {
                    if (!passangers.ContainsKey(pole.station)) {
                        passangers[pole.station] = 0;
                        keys.Insert(0, pole.station);
                    }
                    passangers[pole.station] = (passangers[pole.station] + pole.quantity) % PRIME;
                }
                else
                {
                    long passangersRemaining = pole.quantity;
                    foreach (int k in keys)
                    {
                        if (passangersRemaining == 0)
                            break;
                        long takenPassangers = Math.Min(passangers[k], passangersRemaining);
                        passangersRemaining -= takenPassangers;
                        passangers[k] -= takenPassangers;
                        if (takenPassangers > 0)
                        {
                            totalPricePaid = (totalPricePaid + takenPassangers * (price(k, pole.station))) % PRIME;
                        }
                    }
                }
            }

            return totalPricePaid;
        }

    }
}
