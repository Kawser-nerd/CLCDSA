import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int n = Integer.parseInt(str[0]);
        int m = Integer.parseInt(str[1]);

        long base = (long) 1e9 + 7;

        long ans = 1;

        if (Math.abs(n - m) == 0) {
            ans *= 2;
            ans %= base;
        } else if (Math.abs(n - m) > 1) {
            System.out.println(0);
            System.exit(0);
        }

        for (int i = 1; i <= n; i++) {
            ans *= i;
            ans %= base;
        }

        for (int i = 1; i <= m; i++) {
            ans *= i;
            ans %= base;
        }

        System.out.println(ans);
    }

}