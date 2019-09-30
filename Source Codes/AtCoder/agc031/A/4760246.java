import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int[] cNum = new int['z' + 1];
        sc.nextInt();
        char[] s = sc.next().toCharArray();
        for (char c : s) {
            cNum[c]++;
        }

        long MOD = 1000_000_000l + 7l;
        long ans = 1l;
        for (int i = 'a'; i <= 'z'; i++) {
            ans = (ans * (cNum[i] + 1)) % MOD;
        }
        System.out.println(ans - 1l);
    }
}