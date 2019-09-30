using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace atcoder_beginner_001D
{
    class Program
    {
        static void Main(string[] args)
        {

            var line1 = Console.ReadLine();
            int N = int.Parse(line1);

            List<Rain> rains = new List<Rain>();
            for(int i = 0; i < N; i++)
            {
                var line = Console.ReadLine().Split('-').ToArray();
                Rain rain = new Rain(int.Parse(line[0]), int.Parse(line[1]));
                rains.Add(rain);
            }

            rains.Sort((x, y) => x.rst.CompareTo(y.rst));

            List<Rain> ans = new List<Rain>();
            ans.Add(rains[0]);
            foreach(Rain r in rains)
            {
                if (r.rst > ans.Last().rft)
                {
                    ans.Add(r);
                }
                else if (r.rft > ans.Last().rft)
                {
                    ans.Last().rft = r.rft;
                }

            }
            
            foreach(Rain r in ans)
            {
                Console.WriteLine(string.Format("{0:0000}", r.rst) + "-" + string.Format("{0:0000}", r.rft));
            }
            Console.ReadKey();
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
            //????60????????
            if (rft % 100 == 60)
            {
                rft += 40;
            }
        }
    }
}