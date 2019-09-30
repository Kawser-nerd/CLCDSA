using System;
using System.Linq;

namespace Sample101
{
    class Program
    {
        static void Main(string[] args)
        {
            var line = Console.ReadLine().Split(' ');
            var city_count = int.Parse(line[0]);
            var road_count = int.Parse(line[1]);

            var city_road = new int[city_count];

            for (int i = 0; i < road_count; ++i)
            {
                var road_data = Console.ReadLine().Split(' ').Select(str => int.Parse(str)).ToArray();
                city_road[road_data[0] - 1]++;
                city_road[road_data[1] - 1]++;
            }

            for (int i = 0; i < city_count; ++i)
            {
                Console.WriteLine(city_road[i]);
            }
        }
    }
}