import java.util.*;
import java.io.*;

public class C
{
    public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            int N = input.nextInt();
            PriorityQueue<Hiker> hikers = new PriorityQueue<Hiker>();
            for (int i = 0; i < N; i++)
            {
                int D = input.nextInt();
                int H = input.nextInt();
                int M = input.nextInt();
                for (int j = 0; j < H; j++)
                    hikers.add(new Hiker(D, M + j));
            }

            long minEncounters = Long.MAX_VALUE;
            int numHikers = hikers.size();
            int numEncounters = 0;
            int numPassed = 0;
            for (int i = 0; i < 3 * numHikers; i++)
            {
                Hiker next = hikers.poll();
                if (next.passed)
                    numEncounters++;
                else
                    numPassed++;
                next.passed = true;
                next.cross += 360L * next.M;
                hikers.add(next);
                if (numEncounters + numHikers - numPassed < minEncounters)
                    minEncounters = numEncounters + numHikers - numPassed;
            }

            System.out.printf("Case #%d: ", n + 1);
            System.out.println(minEncounters);
        }
    }

    static class Hiker implements Comparable<Hiker>
    {
        int D;
        int M;
        long cross;
        boolean passed;

        Hiker(int D, int M)
        {
            this.D = D;
            this.M = M;
            this.cross = (360L - D) * M;
            this.passed = false;
        }

        public int compareTo(Hiker other)
        {
            if (cross > other.cross)
                return 1;
            else if (cross < other.cross)
                return -1;
            else if (passed && !other.passed)
                return -1;
            else if (!passed && other.passed)
                return 1;
            return 0;
        }
    }
}
