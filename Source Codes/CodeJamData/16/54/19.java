import java.util.*;
import java.io.*;
import static lib.Util.*;

public class D
{
    static int ans;

    public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            int N = input.nextInt();
            int L = input.nextInt();
            String[] Gs = new String[N];
            for (int i = 0; i < N; i++)
                Gs[i] = input.next();
            String B = input.next();

            boolean bad = false;
            for (String G : Gs)
                if (G.equals(B))
                    bad = true;
            if (bad)
            {
                System.out.printf("Case #%d: IMPOSSIBLE\n", n + 1);
                continue;
            }

            if (L == 1)
            {
                System.out.printf("Case #%d: 0 ?\n", n + 1);
                continue;
            }

            StringBuilder p1 = new StringBuilder();
            StringBuilder p2 = new StringBuilder();
            for (int i = 0; i < L; i++)
            {
                if (i == L - 1)
                {
                    if (i % 2 == 0)
                        p2.append("?1");
                    else
                        p1.append("?1");
                }
                else if (i % 2 == 0)
                {
                    p1.append("10");
                    p2.append("?");
                }
                else
                {
                    p1.append("?");
                    p2.append("10");
                }
            }

            System.out.printf("Case #%d: %s %s\n", n + 1, p1, p2);
        }
    }
}

