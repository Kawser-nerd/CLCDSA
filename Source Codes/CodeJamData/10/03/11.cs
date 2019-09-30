using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProgrammingContest.GoogleCodeJam._2010.Qual
{
    class C
    {
        long R;
        long k;
        int N;

        long[] num;
        long[] memo;
        long[] visitedTimes;

        int index = 0;
        long total = 0;
        Queue<long> wait = new Queue<long>();
        Queue<long> ride = new Queue<long>();

        public void Init(StreamReader sr)
        {
            string[] s = sr.ReadLine().Split(' ');
            R = long.Parse(s[0]);
            k = long.Parse(s[1]);
            N = int.Parse(s[2]);

            num = new long[N];
            memo = new long[N];
            visitedTimes = new long[N];

            s = sr.ReadLine().Split(' ');
            for (int j = 0; j < N; j++)
            {
                num[j] = long.Parse(s[j]);
                memo[j] = -1;
                visitedTimes[j] = -1;
                wait.Enqueue(num[j]);
            }

            index = 0;
            total = 0;
            visitedTimes[0] = 0;
            memo[0] = 0;
        }

        bool Next(int n)
        {
            long money = 0;
            long person = 0;

            for (; k >= num[index] + person && wait.Any(); index = (index + 1) % N)
            {
                money += num[index];
                person += num[index];
                ride.Enqueue(wait.Dequeue());
            }

            while (ride.Any()) wait.Enqueue(ride.Dequeue());

            total += money;

            if (visitedTimes[index] != -1) return true;

            memo[index] = total;
            visitedTimes[index] = n;
            return false;
        }

        long cycle = 0;
        long beforeCycle = 0;
        long afterCycle = 0;

        long cycleMoney = 0;
        long beforeCycleMoney = 0;
        long afterCycleMoney = 0;
        public void CalcCycle()
        {
            for (int i = 0; i < R; i++)
            {
                if (Next(i + 1))
                {
                    //Console.WriteLine("checkend {0}!!!", i);
                    cycle = i - visitedTimes[index] + 1;
                    beforeCycle = visitedTimes[index];
                    afterCycle = (R - beforeCycle) % cycle;

                    cycleMoney = (R - beforeCycle) / cycle * (total - memo[index]);
                    beforeCycleMoney = memo[index];
                    break;
                }
                    //Console.WriteLine("check {0}!!!", i);
            }

                //Console.WriteLine("afterCycleMoney {0}!!!", afterCycle);
            if (cycle == 0)
            {
                beforeCycle = index;
                beforeCycleMoney = total;
                return;
            }

            int idx = index;
            for (int i = 0; i < afterCycle; i++)
            {
                long money = 0;
                long person = 0;

                for (; k >= num[idx] + person && wait.Any(); idx = (idx + 1) % N)
                {
                    money += num[idx];
                    person += num[idx];
                    ride.Enqueue(wait.Dequeue());
                }
                while (ride.Any()) wait.Enqueue(ride.Dequeue());

                afterCycleMoney += money;
                //Console.WriteLine("afterCycleMoney {0}!!!", money);
            }
        }

        public void Solve(StreamWriter sw, int i)
        {
            CalcCycle();
            long ret = beforeCycleMoney + cycleMoney + afterCycleMoney;
            //sw.WriteLine(":{0}, {1}", beforeCycle, beforeCycleMoney);
            //sw.WriteLine(":{0}, {1}", cycle, cycleMoney);
            //sw.WriteLine(":{0}, {1}", afterCycle, afterCycleMoney);
            sw.WriteLine("Case #{0}: {1}", i, ret);
        }

        public static void Main(string[] args)
        {
            using (FileStream os = new FileStream(@"result.txt", FileMode.Create))
            using (StreamWriter sw = new StreamWriter(os))
            using (FileStream fs = new FileStream(args[0], FileMode.Open))
            using (StreamReader sr = new StreamReader(fs))
            {
                int t = int.Parse(sr.ReadLine());
                for (int i = 0; i < t; i++)
                {
                    //Console.WriteLine("try {0}", i);
                    var x = new C();
                    x.Init(sr);
                    x.Solve(sw,i+1);
                }
            }
            //Console.ReadKey();
        }
    }
}
