import java.util.*;
import java.io.*;

public class B
{
    static int N;

    static double ans;

    public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            N = input.nextInt();
            int K = input.nextInt();

            double[] ps = new double[N];
            for (int i = 0; i < N; i++)
                ps[i] = input.nextDouble();

            ans = 0;
            solve(new ArrayList<Double>(), ps, K, 0);

            System.out.printf("Case #%d: ", n + 1);
            System.out.println(ans);
        }
    }

    static void solve(List<Double> keep, double[] ps, int K, int index)
    {
        if (index == ps.length)
        {
            if (keep.size() == K)
                check(keep, K);
            return;
        }
        solve(keep, ps, K, index + 1);
        keep.add(ps[index]);
        solve(keep, ps, K, index + 1);
        keep.remove(keep.size() - 1);
    }

    static void check(List<Double> keep, int K)
    {
        double[][] table = new double[K + 1][K + 1];
        table[0][0] = 1;
        for (int i = 1; i <= K; i++)
            for (int yes = 0; yes <= i; yes++)
            {
                table[i][yes] = table[i - 1][yes] * (1 - keep.get(i - 1));
                if (yes > 0)
                    table[i][yes] += table[i - 1][yes - 1] * keep.get(i - 1);
            }
        if (table[K][K / 2] > ans)
            ans = table[K][K / 2];
    }
}
