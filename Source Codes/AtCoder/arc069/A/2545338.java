import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        long M = sc.nextLong();
        System.out.println( solve(N, M) );
    }

    private static long solve(long N, long M) {
        // (1, 2) or (0, 4)?????

        long ans = 0;
        // (1, 2)
        long scc12 = Math.min(N, M / 2);
        ans += scc12;
        N -= scc12;
        M -= scc12 * 2;

        // (0, 4)
        long scc04 = M / 4;
        ans += scc04;

        return ans;
    }
}