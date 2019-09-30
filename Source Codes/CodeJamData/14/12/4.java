import java.util.*;
import java.io.*;

public class B
{
    static int N;
    static List<Integer>[] g;
    static int ans;

    public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            N = input.nextInt();
            g = (List<Integer>[])new List[N];
            for (int i = 0; i < N; i++)
                g[i] = new ArrayList<Integer>();

            for (int j = 0; j < N - 1; j++)
            {
                int start = input.nextInt() - 1;
                int end = input.nextInt() - 1;
                g[start].add(end);
                g[end].add(start);
            }

            ans = N - 1;
            for (int i = 0; i < N; i++)
            {
                int m = solve(i, -1)[0];
                if (m < ans)
                    ans = m;
            }

            System.out.printf("Case #%d: %d\n", n + 1, ans);
        }
    }

    static int[] solve(int v, int p)
    {
        List<int[]> subs = new ArrayList<int[]>();
        for (int child : g[v])
            if (child != p)
                subs.add(solve(child, v));

        if (subs.size() == 0)
            return new int[] {0, 1};
        else if (subs.size() == 1)
            return new int[] {subs.get(0)[1], subs.get(0)[1] + 1};
        else
        {
            int sum = 0;
            for (int[] ints : subs)
                sum += ints[1];
            List<Integer> diffs = new ArrayList<Integer>();
            for (int[] ints : subs)
                diffs.add(ints[0] - ints[1]);
            Collections.sort(diffs);
            return new int[] {sum + diffs.get(0) + diffs.get(1), sum + 1};
        }
    }
}
