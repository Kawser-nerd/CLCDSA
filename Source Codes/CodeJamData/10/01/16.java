import java.util.*;

public final class A
{
    public static final void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        for (int t = 0; t < T; ++t)
        {
            int N = scanner.nextInt(), k = scanner.nextInt();
            // System.out.printf("N = %d, k = %d%n", N, k);
            boolean stat = ((k + 1) & ((1 << N) - 1)) == 0;
            System.out.printf("Case #%d: %s%n", 1 + t, stat ? "ON" : "OFF");
        }
    }
}
