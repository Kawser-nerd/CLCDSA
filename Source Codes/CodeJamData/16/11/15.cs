using System;
using System.IO;

class A
{
    public void Solve()
    {
        StreamReader reader = new StreamReader("A_in.txt");
        StreamWriter writer = new StreamWriter("A_out.txt");

        int T = Int32.Parse(reader.ReadLine());

        for (int t = 0; t < T; t++)
        {
            string S = reader.ReadLine();

            string answer = S[0].ToString();

            for (int i = 1; i < S.Length; i++)
            {
                char next = S[i];
                char currentLeader = answer[0];

                if (next >= currentLeader) answer = next.ToString() + answer;
                else answer = answer + next.ToString();
            }

            
            writer.WriteLine("Case #{0}: {1}", (t + 1), answer);
            Console.WriteLine("Case #{0}: {1}", (t + 1), answer);
        }

        reader.Close();
        writer.Close();
    }


}
