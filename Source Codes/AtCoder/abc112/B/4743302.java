import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();
        int T = sc.nextInt();

        int[] c = new int[N];
        int[] t = new int[N];

        int minCost = Integer.MAX_VALUE;
        for (int i = 0; i < N; i++) {
            c[i] = sc.nextInt();
            t[i] = sc.nextInt();
            if (t[i] <= T) {
                minCost = Math.min(minCost, c[i]);
            }
        }
        if (minCost == Integer.MAX_VALUE) {
            System.out.println("TLE");
            return;
        }
        System.out.println(minCost);
    }
}