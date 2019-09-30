import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
    private static int n;
    private static long a, b;
    private static long[] enemy;

    private static boolean C(long k) {
        long cnt = 0;
        for (long hp : enemy) {
            hp -= b * k;
            if (hp > 0) {
                cnt += Math.ceil((double) hp / (a - b));
            }
        }

        if (cnt > k) return false;
        else return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        n = Integer.parseInt(str[0]);
        a = Long.parseLong(str[1]);
        b = Long.parseLong(str[2]);

        enemy = new long[n];
        for (int i = 0; i < n; i++) enemy[i] = Long.parseLong(br.readLine());

        long l = 0, r = (long) 1e9+1, med = -1;
        while (r - l > 0) {
            med = (r + l) / 2;
            if (C(med)) {
                r = med;
            } else {
                l = med + 1;
            }
        }
        System.out.println(l);
    }
}