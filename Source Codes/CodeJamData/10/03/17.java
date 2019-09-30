import java.util.*;

public final class C
{
    public static final void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        for (int t = 0; t < T; ++t)
        {
            int R = scanner.nextInt(), k = scanner.nextInt(), N = scanner.nextInt();
            int[] g = new int[N];
            for (int n = 0; n < N; ++n)
            {
                g[n] = scanner.nextInt();
            }
            int[] gains = new int[N];
            int[] nexts = new int[N];
            for (int n = 0; n < N; ++n)
            {
                for (int c = 0; c < N && gains[n] + g[(n + c) % N] <= k; ++c)
                {
                    gains[n] += g[(n + c) % N];
                    nexts[n] = (n + c + 1) % N;
                }
            }
            // System.out.printf("R = %d, k = %d, N = %d%n", R, k, N);
            // System.out.println("g = " + Arrays.toString(g));
            // System.out.println("gains = " + Arrays.toString(gains));
            // System.out.println("nexts = " + Arrays.toString(nexts));
            long gain = 0;
            for (int r = 0, index = 0; r < R; ++r)
            {
                gain += gains[index];
                index = nexts[index];
            }
            System.out.printf("Case #%d: %d%n", 1 + t, gain);
        }
    }
}
