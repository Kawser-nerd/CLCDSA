import java.util.Arrays;
import java.util.Scanner;

public class Main {
    int n, k;
    public static void main(String[] args) {
        Main m = new Main();
        m.read();
        m.solve();
    }

    private void read() {
        Scanner sc = new Scanner(System.in);
        k = sc.nextInt();
        n = sc.nextInt();
    }

    private void solve() {
        if (k % 2 == 0) {
            StringBuilder sb = new StringBuilder();
            sb.append(k / 2);
            for (int i = 1; i < n; i++) {
                sb.append(" ");
                sb.append(k);
            }
            System.out.println(sb.toString());
            return;
        }
        int[] ns = new int[n];
        int cnt = n  / 2;
        Arrays.fill(ns, (k + 1) / 2);
        int trg = n - 1;
        for (int i = 0; i < cnt; i++) {
            while (trg >= 0 && ns[trg] == 0) trg--;
            if (ns[trg] == 1) {
                ns[trg] = 0;
            }
            else {
                ns[trg]--;
                for (int j = trg + 1; j < n; j++) {
                    ns[j] = k;
                    trg++;
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int n: ns)
            if (n != 0)
                sb.append(n + " ");
        System.out.println(sb.toString().trim());
    }
}