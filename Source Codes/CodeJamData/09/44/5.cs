using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class A
    {
        static void Main(string[] args)
        {
            StreamReader input = new StreamReader("d.in.txt");
            StreamWriter output = new StreamWriter("d.out.txt");

            int tc = Int32.Parse(input.ReadLine());

            for (int i = 0; i < tc; i++)
                output.WriteLine("Case #{0}: {1}", i + 1, solveCase(input));

            input.Close();
            output.Close();
        }


        class Plant
        {
            public Plant(string s)
            {
                var split = Array.ConvertAll(s.Split(), ss => int.Parse(ss));
                X = split[0];
                Y = split[1];
                R = split[2];
            }
            public double X { get; set; }
            public double Y { get; set; }
            public double R { get; set; }
        }

        private static double solveCase(StreamReader input)
        {
            int plantCount = int.Parse(input.ReadLine());
            
            List<Plant> plants = new List<Plant>();
            for(int i=0;i<plantCount;i++)
                plants.Add(new Plant(input.ReadLine()));

            if (plantCount == 1)
                return plants[0].R;
            if (plantCount == 2)
                return Math.Max(plants[0].R, plants[1].R);
            if (plantCount == 3)
                return Math.Min(
                    Math.Min(
                            Math.Max(plants[0].R, slv(plants[1], plants[2])),
                            Math.Max(plants[1].R, slv(plants[0], plants[2]))
                        ),
                            Math.Max(plants[2].R, slv(plants[0], plants[1]))
                    );

            throw new NotImplementedException();
        }

        private static double slv(Plant plant1, Plant plant2)
        {
            var dx = plant2.X-plant1.X;
            var dy = plant2.Y-plant1.Y;
            var distance = Math.Sqrt(dx * dx + dy * dy);
            return (distance + plant1.R + plant2.R) / 2.0;
        }
    }
}
