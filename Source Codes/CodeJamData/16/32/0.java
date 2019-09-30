import java.util.*;
import java.io.*;

public class B
{
    static int N;

    static int ans;

    public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            int B = input.nextInt();
            long M = input.nextLong();

            if (M > (1L << (B - 2)))
            {
                System.out.printf("Case #%d: IMPOSSIBLE\n", n + 1);
                continue;
            }

            boolean[][] slides = new boolean[B][B];
            if (M == (1L << (B - 2)))
            {
            for (int i = 0; i < B; i++)
                for (int j = i + 1; j < B; j++)
                    slides[i][j] = true;
            }
            for (int i = 0; i + 1 < B; i++)
                for (int j = i + 1; j + 1 < B; j++)
                    slides[i][j] = true;
            for (int i = 0; i + 2 < B; i++)
                if ((M & (1L << i)) > 0)
                    slides[i + 1][B - 1] = true;

            System.out.printf("Case #%d: POSSIBLE\n", n + 1);
            for (int i = 0; i < B; i++)
            {
                for (int j = 0; j < B; j++)
                    System.out.print(slides[i][j] ? '1' : '0');
                System.out.println();
            }
        }
    }
}
