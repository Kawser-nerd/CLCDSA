using System;
using System.Collections.Generic;
using System.IO;

class C
{
    int biggestCircle;
    int[] BFFs;
    int N;

    public void Solve()
    {
        StreamReader reader = new StreamReader("C_in.txt");
        StreamWriter writer = new StreamWriter("C_out.txt");

        int T = Int32.Parse(reader.ReadLine());

        for (int t = 0; t < T; t++)
        {
            biggestCircle = 0;
            N = Int32.Parse(reader.ReadLine());
            string[] BFFsplit = reader.ReadLine().Split();

            BFFs = new int[N];
            for (int i = 0; i < N; i++)
            {
                BFFs[i] = Int32.Parse(BFFsplit[i]) - 1;
            }

            
            // Loop over starting kids
            for (int i = 0; i < N; i++)
            {
                List<int> circle = new List<int>();
                circle.Add(i);

                NextKid(circle);
            }


            writer.WriteLine("Case #{0}: {1}", (t + 1), biggestCircle);
            Console.WriteLine("Case #{0}: {1}", (t + 1), biggestCircle);
        }

        reader.Close();
        writer.Close();
    }

    void NextKid(List<int> circle)
    {
        // Find the BFF of the last kid to be sat down
        int lastKid = circle[circle.Count - 1];
        int lastKidsBFF = BFFs[lastKid];

        // Case 1: the kid's BFF is already next to him on the other side
        if ((circle.Count >= 2) && (circle[circle.Count - 2] == lastKidsBFF))
        {
            // This could be a valid circle
            biggestCircle = Math.Max(biggestCircle, circle.Count);

            // And you could choose from any of the remaining kids
            for (int j = 0; j < N; j++)
            {
                if (circle.Contains(j)) continue;

                circle.Add(j);
                NextKid(circle);
                circle.Remove(j);
            }
        }

        // Case 2: the kid's BFF is at the start of the circle
        else if (lastKidsBFF == circle[0])
        {
            biggestCircle = Math.Max(biggestCircle, circle.Count);
        }

        // Case 3: the kid's BFF can be sat down
        else if (circle.Contains(lastKidsBFF) == false)
        {
            circle.Add(lastKidsBFF);
            NextKid(circle);
            circle.Remove(lastKidsBFF);
        }

        // Case 4: the kid's BFF is already on the circle
        else if (circle.Contains(lastKidsBFF) == true)
        {

        }

    }


}
