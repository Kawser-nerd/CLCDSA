using System;
using System.Collections.Generic;

namespace ABC001D{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            List<Rain> rains = new List<Rain>();
            for (int i = 0; i < n; i++) {
                var line = Console.ReadLine().Split('-');
                Rain rain = new Rain(int.Parse(line[0]), int.Parse(line[1]));
                rains.Add(rain);
            }
            rains.Sort((x, y) => x.rst-y.rst);

            List<Rain> answers = new List<Rain>();
            Rain current = null;

            foreach (Rain rain in rains) {
                if (current == null)
                {
                    current = rain;
                } else {
                    if (current.rft >= rain.rst) {
                        current.rft = Math.Max(rain.rft, current.rft);
                    } else {
                        answers.Add(current);
                        current = rain;
                    }
                }
            }
            if (current != null) {
                answers.Add(current);
            }

            foreach (Rain answer in answers)
            {
                Console.WriteLine("{0:0000}-{1:0000}", answer.rst, answer.rft);
            }
        }
    }

    class Rain
    {
        public int rst { get; set; }
        public int rft { get; set; }

        public Rain(int st, int ft)
        {
            rst = st - st % 5;
            if (ft % 5 == 0)
            {
                rft = ft;
            }
            else rft = ft - ft % 5 + 5;
            if (rft % 100 == 60)
            {
                rft += 40;
            }
        }
    }

}