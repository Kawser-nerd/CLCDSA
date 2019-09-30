import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int n = sc.nextInt();
        int[] primePow = new int[n + 1];
        Arrays.fill(primePow, 1);
        for (int i = 2; i <= n; i++) {
            int tmp = i;
            for (int j = 2; tmp != 1; j++) {
                while (tmp % j == 0) { 
                    primePow[j]++;
                    tmp /= j;
                }
            }
        }
        long ans = 1;
        for (int i = 0; i < n +1; i++) {
            ans = (ans * primePow[i]) % (1_000_000_000 + 7);
        }
        System.out.println(ans);
    }
}