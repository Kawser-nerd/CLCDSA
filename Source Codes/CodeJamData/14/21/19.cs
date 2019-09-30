using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
    public class Solver
    {
        int answer;
        bool hasAnswer;
        List<string> rows = new List<string>();
        List<List<char>> chars = new List<List<char>>();
        List<List<int>> groups = new List<List<int>>();
        int cnt;

        public void Run()
        {
            using (FileStream input = new FileStream("A-small-attempt1.in", FileMode.Open))
            //using (FileStream input = new FileStream("input.txt", FileMode.Open))
            using (FileStream output = new FileStream("output.txt", FileMode.Create))
            using (StreamReader reader = new StreamReader(input))
            using (StreamWriter writer = new StreamWriter(output))
            {
                int test = Int32.Parse(reader.ReadLine());
                for (int tt = 0; tt < test; tt++)
                {
                    ReadInput(reader);
                    SolveTask();
                    WriteOutput(writer, tt + 1);
                }
            }

        }

        private void SolveTask()
        {
            groups.Clear();
            chars.Clear();
            answer = 0;
            for (int i = 0; i < cnt; i++)
            {
                List<int> group = new List<int>();
                List<char> rowChar = new List<char>();
                int num = 1;
                char c = rows[i][0];
                for (int j = 1; j < rows[i].Length; j++)
                {
                    if (rows[i][j]!=rows[i][j-1])
                    {
                        group.Add(num);
                        rowChar.Add(c);
                        num = 1;
                        c = rows[i][j];
                    }
                    else
                    {
                        num++;
                    }
                }
                if (rows[i].Length>0)
                {
                    group.Add(num);
                    rowChar.Add(c);
                }
                groups.Add(group);
                chars.Add(rowChar);
            }
            hasAnswer = true;
            int len = groups[0].Count;
            for (int i=1;i<cnt;i++)
            {
                if (groups[i].Count!=groups[0].Count)
                {
                    hasAnswer = false;
                    break;
                }
                for (int j=0;j<len;j++)
                {
                    if (chars[i][j]!=chars[0][j])
                    {
                        hasAnswer = false;
                        break;
                    }
                }
            }
            if (hasAnswer)
            {
                for (int j=0;j<len;j++)
                {
                    int avg = 0;
                    for (int i=0;i<cnt;i++)
                    {
                        avg += groups[i][j];
                    }
                    avg = avg / cnt;
                    for (int i = 0; i < cnt; i++)
                    {
                        answer += Math.Abs(avg - groups[i][j]);
                    }
                }
            }
        }

        private void WriteOutput(StreamWriter writer, int testNum)
        {
            writer.WriteLine(string.Format("Case #{0}: {1}", testNum, (hasAnswer) ? answer.ToString() : "Fegla Won"));
        }

        private void ReadInput(StreamReader reader)
        {
            rows.Clear();
            cnt = Int32.Parse(reader.ReadLine());
            for (int i = 0; i < cnt; i++)
            {
                string inp = reader.ReadLine();
                rows.Add(inp);
            }
        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            (new Solver()).Run();
        }

    }
}
