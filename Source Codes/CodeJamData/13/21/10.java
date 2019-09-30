import java.util.Arrays;
import java.util.Scanner;

public class A {
    int calc(int a, int[] b) {
        int i = 0;
        int res = 0;
        if (a == 1) {
            return 100000;
        }
        while (i < b.length) {
            if (b[i] < a) {
                a += b[i];
                i++;
            } else {
                a += a - 1;
                res++;
            }
        }
        return res;
    }

    void solve(int a, int[] b) {
        Arrays.sort(b);
        int best = b.length;
        for (int i = 0; i <= b.length; i++) {
            best = Math.min(best, calc(a, Arrays.copyOf(b, i)) + (b.length - i));
        }
        System.out.println(best);
    }

    void run() {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int it = 0; it < t; it++) {
            System.out.print("Case #" + (it + 1) + ": ");
            int a = in.nextInt();
            int n = in.nextInt();
            int[] b = new int[n];
            for (int i = 0; i < n; i++) {
                b[i] = in.nextInt();
            }
            solve(a, b);
        }
    }


    public static void main(String[] args) {
        new A().run();
    }
}
