using System;
using System.Collections.Generic;
using System.Linq;

namespace Solution
{
    public struct Request
    {
        public int first;
        public int second;
    }

    public struct Problem
    {
        public int island;
        public int request;
        public List<Request> requests;
    }

    public class Parser
    {
        public static Problem Parse(List<string> lines)
        {
            var info = lines[0].Split(' ');
            var island = int.Parse(info[0]);
            var request = int.Parse(info[1]);

            var requests = new List<Request>();
            foreach (var line in lines.Skip(1))
            {
                var split = line.Split(' ');
                var req = new Request()
                {
                    first = int.Parse(split[0]),
                    second = int.Parse(split[1])
                };
                requests.Add(req);
            }

            return new Problem()
            {
                island = island,
                request = request,
                requests = requests
            };
        }
    }

    public class Solution
    {
        Problem problem;

        public Solution(Problem problem)
        {
            this.problem = problem;
        }

        public int Solve()
        {
            var bridge = 0;
            var requests = this.problem.requests.OrderBy(r => r.second).ToArray();
            while (requests.Length > 0)
            {
                var position = requests[0].second;
                bridge += 1;
                requests = requests.Where(r => r.first >= position).ToArray();
            }
            return bridge;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var lines = new List<string>();
            while (true)
            {
                var line = Console.ReadLine();
                if (line == null)
                {
                    break;
                }
                lines.Add(line);
            }
            var problem = Parser.Parse(lines);
            var solution = new Solution(problem);
            Console.WriteLine(solution.Solve());
        }
    }
}