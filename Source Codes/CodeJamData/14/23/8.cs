using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;
using System.Threading;
using System.Numerics;

namespace C
{
    class City
    {
        public int id;
        public int new_id;
        public string ZIP;
        public SortedSet<int> connected = new SortedSet<int>();
        public SortedSet<int> new_connected = new SortedSet<int>();
    }

    class Model
    {
        public int current_city;
        public SortedSet<int>[] connections;
        public int[] must_return;
    }

    class Program
    {
        static int N;
        static bool[] used;
        static int[] order;
        static City[] g_cities;
        static string solution;

        static bool Check()
        {
            Model model = new Model();
            model.current_city = order[0];
            model.connections = new SortedSet<int>[N];
            for (int i = 0; i < N; i++)
                model.connections[i] = new SortedSet<int>( g_cities[i].new_connected );
            model.must_return = new int[N];
            for (int i = 0; i < N; i++)
                model.must_return[i] = -1;


            for (int i = 1; i < N; i++)
            {
                // move model to city i
                int next = order[i];

                while (model.current_city != -1 && !model.connections[model.current_city].Contains(next))
                {
                    model.current_city = model.must_return[model.current_city];
                }

                if (model.current_city == -1)
                    return false;

                model.connections[model.current_city].Remove(next);
                int prev = model.current_city;
                model.current_city = next;
                model.must_return[model.current_city] = prev;
            }

            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < N; i++)
            {
                string ZIP = g_cities.Single(cc => cc.new_id == order[i]).ZIP;
                sb.Append(ZIP);
            }
            solution = sb.ToString();

            return true;
        }

        static bool permute(int p)
        {
            if (p == N)
            {
                return Check();
            }

            for(int i = 0; i < N; i++)
                if (!used[i])
                {
                    used[i] = true;
                    order[p] = i;
                    if(permute(p + 1))
                        return true;
                    used[i] = false;
                }

            return false;
        }

        static string Solve(City[] cities)
        {
            N = cities.Length;
            used = new bool[N];
            order = new int[N];

            Array.Sort(cities, (a, b) => a.ZIP.CompareTo(b.ZIP));
            for (int i = 0; i < N; i++)
                cities[i].new_id = i;

            for (int i = 0; i < N; i++)
            {
                foreach (var id in cities[i].connected)
                {
                    int new_id = cities.Single(cc => cc.id == id).new_id;
                    cities[i].new_connected.Add(new_id);
                }
            }

            g_cities = cities;
            permute(0);

            return solution;
        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                string[] line = Console.ReadLine().Split();
                int N = int.Parse(line[0]);
                int M = int.Parse(line[1]);

                City[] cities = new City[N];
                for (int i = 0; i < N; i++)
                {
                    cities[i] = new City { id = i };
                    string ZIP = Console.ReadLine();
                    cities[i].ZIP = ZIP;
                }


                for (int i = 0; i < M; i++)
                {
                    line = Console.ReadLine().Split();
                    int a = int.Parse(line[0]) - 1;
                    int b = int.Parse(line[1]) - 1;

                    cities[a].connected.Add(b);
                    cities[b].connected.Add(a);
                }

                Console.WriteLine("Case #{0}: {1}", t, Solve(cities));
            }
        }
    }
}
