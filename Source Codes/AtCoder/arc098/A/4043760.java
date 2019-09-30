import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int n =sc.nextInt();
        char[] s = sc.next().toCharArray();
        int[] wSums = new int[n + 1];
        int[] eSums = new int[n + 1];
        wSums[0] = 0;
        eSums[0] = 0;
        for (int i = 0; i < n; i++) {
            wSums[i + 1] = s[i] == 'W' ? wSums[i] + 1 :wSums[i];
            eSums[i + 1] = s[i] == 'E' ? eSums[i] + 1 :eSums[i];
        }

        int ans = 300001;
        for (int i = 0; i < n; i++) {
            int tmpAns = wSums[i] + eSums[n] - eSums[i + 1];
            ans = Math.min(ans, tmpAns);
        }
        System.out.println(ans);
    }
}