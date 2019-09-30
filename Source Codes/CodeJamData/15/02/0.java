import java.util.*;
import java.io.*;

public class B
{
    public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            int N = input.nextInt();
            int[] ps = new int[N];
            for (int i = 0; i < N; i++)
                ps[i] = input.nextInt();

            int[] counts = new int[1005];
            for (int p : ps)
                counts[p]++;

            int min = 10000;
            for (int lim = 1; lim <= counts.length; lim++)
            {
                int moves = 0;
                for (int i = 0; i < counts.length; i++)
                    moves += ((i - 1) / lim) * counts[i];
                if (moves + lim < min)
                    min = moves + lim;
            }
            System.out.printf("Case #%d: %d\n", n + 1, min);
        }
    }
}

