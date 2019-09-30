using System;
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
            // Load info
            string[] line1 = reader.ReadLine().Split();
            ulong B = UInt64.Parse(line1[0]);
            ulong N = UInt64.Parse(line1[1]);

            string[] line2 = reader.ReadLine().Split();
            ulong[] Mk = new ulong[B];
            for (ulong i = 0; i < B; i++)
            {
                Mk[i] = UInt64.Parse(line2[i]);
            }

            // We need to find a time t where there's a manageable number of barbers still to go. So we do a binary search to find the time taken to get to just before N.
            ulong low = 0;
            ulong high = (ulong)100000 * (ulong)1000000000;
            ulong target = N-1;
            //Console.WriteLine("Target is {0}", target);

            while (low + 1 < high)
            {
                ulong mid = (low + high) / 2;
                ulong p = PeopleSeen(mid, B, Mk);

                //Console.WriteLine("Tried time {0}, returned {1} ", mid, p);

                if (p == target) { low = mid; break; }

                if (p > target)
                {
                    high = mid - 1;
                    continue;
                }

                if (p < target)
                {
                    low = mid;
                    continue;
                }

            }

            //Console.WriteLine("We think a good time to start from is {0}", low);

            // Now we go manually. We go to the time given above and see how many people have been seen and when barbers will be free.
            ulong barber = ChooseBarber(low, B, Mk, N);

            string answer = String.Format("Case #{0}: {1}", (t + 1), (barber + 1));
            writer.WriteLine(answer);
            Console.WriteLine(answer);
        }

        reader.Close();
        writer.Close();
    }

    // If all barbers are busy (i.e. when the problem gets hard), this works out the number of people who have been admitted (but who have not left).
    public ulong PeopleSeen(ulong minutes, ulong B, ulong[] Mk)
    {
        if (minutes == 0) return 0;

        ulong peopleSeen = 0;
        for (ulong b = 0; b < B; b++)
        {
            peopleSeen += 1 + minutes / Mk[b];
        }
        return peopleSeen;
    }

    public ulong ChooseBarber(ulong minutes, ulong B, ulong[] Mk, ulong N)
    {
        // How many barbers do we need to wait for? Place = 1 means we're next.
        ulong[] nextFree = new ulong[B];
        for (ulong b = 0; b < B; b++)
        {
            if (minutes == 0) nextFree[b] = 0;
            else nextFree[b] = (1 + (minutes / Mk[b])) * Mk[b];
        }

        //Console.WriteLine("Barbers are next free:");
        //for (ulong b = 0; b < B; b++) Console.Write(nextFree[b] + "\t");
        //Console.WriteLine();


        ulong peopleSeen = PeopleSeen(minutes, B, Mk);
        //Console.WriteLine("People seen returned {0}, N is {1}", peopleSeen, N);

        ulong place = N - peopleSeen;
        //Console.WriteLine("Place = {0}", place);
        ulong currentBarber = 0;
        for (ulong i = 0; i < place; i++)
        {
            // Get the next barber
            ulong nextBarber = 0;
            ulong nextTime = UInt64.MaxValue;
            for (ulong b = 0; b < B; b++)
            {
                if (nextFree[b] < nextTime)
                {
                    nextBarber = b;
                    nextTime = nextFree[b];
                }
            }

            // Adjust things
            currentBarber = nextBarber;
            nextFree[nextBarber] += Mk[nextBarber];
        }

        return currentBarber;
    }
}

