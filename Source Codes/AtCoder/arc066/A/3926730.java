import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int n = sc.nextInt();
        int[] as = new int[n];
        for (int i = 0; i < n; i++) {
            as[i] = sc.nextInt();
        }
        Arrays.sort(as);
        
        if (n % 2 == 0) {
            int tmp =  1;
            for (int i = 0; i < n; i += 2) {
                if (as[i] != tmp || as[i + 1] != tmp) {
                    System.out.println(0);
                    return;
                }
                tmp +=2;
            }
        } else {
            if (as[0] != 0) {
                System.out.println(0);
                return;
            }

            int tmp =  2;
            for (int i = 1; i < n; i += 2) {
                if (as[i] != tmp || as[i + 1] != tmp) {
                    System.out.println(0);
                    return;
                }
                tmp +=2;
            }
        }

        int ans = 1;
        for (int i = 0; i < n / 2; i++) {
            ans = (ans * 2) % (1_000_000_000 + 7);
        }
        System.out.println(ans);
    }
}