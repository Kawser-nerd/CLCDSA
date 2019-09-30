import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static int n, k;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        k = sc.nextInt();
        n = sc.nextInt();

        if ((k & 1) == 0) {
            System.out.print(k / 2);
            for (int i = 1; i < n; i++) {
                System.out.print(" ");
                System.out.print(k);
            }
            return;
        }

        int[] ns = new int[n];
        Arrays.fill(ns, (k + 1) / 2);
        int cnt = n / 2;
        int trg = n - 1;

        for (int i = 0; i < cnt; i++) {
            while (trg >= 0 && ns[trg] == 0) trg--;
            if (ns[trg] == 1) {
                ns[trg] = 0;
                continue;
            }

            ns[trg]--;
            for (int j = trg + 1; j < n; j++) {
                ns[j] = k;
                trg++;
            }

        }

        for (int n : ns) {
            if (n != 0) {
                System.out.print(n);
                System.out.print(" ");
            }
        }
    }
}