import java.io.*;
import java.util.*;
import java.util.function.*;

public class Main {
    public static void main(String[] args) {
        new Main().solve();
    }

    int N, K;
    boolean[] D;
    public Main() {
        Scanner in = new Scanner(System.in);
        N = in.nextInt();
        K = in.nextInt();
        D = new boolean[10];
        for (int i = 0; i < K; i++) {
            D[in.nextInt()] = true;
        }
    }

    void solve() {
        Function<Integer, Boolean> ok = (n) -> {
            while (n > 0) {
                if (D[n % 10]) return false;
                n /= 10;
            }
            return true;
        };
        for (int n = N; ; n++) {
            if (ok.apply(n)) {
                System.out.println(n);
                break;
            }
        }
    }
}