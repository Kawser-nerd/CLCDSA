import java.util.*;
import java.io.*;

public class A
{
    static int N;

    static int ans;

    public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            N = input.nextInt();
            int R = input.nextInt();
            int P = input.nextInt();
            int S = input.nextInt();

            Stats stats;
            stats = findStats(N, 'P');
            if (stats.P == P && stats.R == R && stats.S == S)
            {
                System.out.printf("Case #%d: %s", n + 1, alph(stats.order));
            System.out.println();
                continue;
            }
            stats = findStats(N, 'R');
            if (stats.P == P && stats.R == R && stats.S == S)
            {
                System.out.printf("Case #%d: %s", n + 1, alph(stats.order));
            System.out.println();
                continue;
            }
            stats = findStats(N, 'S');
            if (stats.P == P && stats.R == R && stats.S == S)
            {
                System.out.printf("Case #%d: %s", n + 1, alph(stats.order));
            System.out.println();
                continue;
            }

            System.out.printf("Case #%d: %s", n + 1, "IMPOSSIBLE");
            System.out.println();
        }
    }

    static Stats findStats(int N, char end)
    {
        String level = end + "";
        for (int i = 0; i < N; i++)
        {
            StringBuilder sb = new StringBuilder();
            for (char c : level.toCharArray())
            {
                if (c == 'P')
                    sb.append("PR");
                else if (c == 'R')
                    sb.append("RS");
                else if (c == 'S')
                    sb.append("SP");
            }
            level = sb.toString();
        }
        int P = 0, R = 0, S = 0;
        for (char c : level.toCharArray())
        {
            if (c == 'P')
                P++;
            else if (c == 'R')
                R++;
            else if (c == 'S')
                S++;
        }
        return new Stats(P, R, S, level);
    }

    static String alph(String s)
    {
        if (s.length() == 1)
            return s;
        else 
        {
            String s1 = alph(s.substring(0, s.length() / 2));
            String s2 = alph(s.substring(s.length() / 2));
            if (s1.compareTo(s2) <= 0)
                return s1 + s2;
            else
                return s2 + s1;
        }
    }

    static class Stats
    {
        int P, R, S;
        String order;

        Stats(int P, int R, int S, String order)
        {
            this.P = P;
            this.R = R;
            this.S = S;
            this.order = order;
        }

        public String toString()
        {
            return P + " " + R + " " + S + " " + order;
        }
    }
}
