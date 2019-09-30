using System;
using System.Collections.Generic;
using System.IO;

class B
{
    public void Solve()
    {
        StreamReader reader = new StreamReader("B_in.txt");
        StreamWriter writer = new StreamWriter("B_out.txt");

        int T = Int32.Parse(reader.ReadLine());

        for (int t = 0; t < T; t++)
        {
            int N = Int32.Parse(reader.ReadLine());

            Dictionary<int, int> list = new Dictionary<int, int>();

            for (int i = 0; i < 2 * N - 1; i++)
            {
                string[] line = reader.ReadLine().Split();
                foreach (string s in line)
                {
                    int next = Int32.Parse(s);

                    if (list.ContainsKey(next)) list[next] += 1;
                    else list[next] = 1;
                }
            }

            List<int> odds = new List<int>();
            foreach (var kvp in list)
            {
                if (kvp.Value % 2 == 1) odds.Add(kvp.Key);
            }
            odds.Sort();


            string answer = "";
            foreach (int x in odds) answer += " " + x;
            writer.WriteLine("Case #{0}:{1}", (t + 1), answer);
            Console.WriteLine("Case #{0}:{1}", (t + 1), answer);
        }

        reader.Close();
        writer.Close();
    }


}
