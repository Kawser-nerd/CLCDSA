import java.io.IOException;

import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.io.PrintWriter;

import java.util.Arrays;
import java.util.HashMap;

@SuppressWarnings("unchecked")
public class Main {
    static HashMap<Integer, Integer> pf;

    // ?????
    static void primeFactor(int n) {
        int a = 2;

        // JDK 1.8 Map.merge
        // map value increment
        while (a * a <= n) {
            if (n % a == 0) {
                pf.merge(a, 1, Integer::sum);
                n = n / a;
            } else {
                a++;
            }
        }
        pf.merge(n, 1, Integer::sum);
    }

    static int f(int x) {
        int cnt = 0;

        for (Integer i : pf.values())
            if (x - 1 <= i) cnt++;

        return cnt++;
    }

    public static void main(String[] args) throws IOException {
        final String s;

        try (
            BufferedReader reader = new BufferedReader(
                new InputStreamReader(System.in))) {
            s = reader.readLine();
        }

        PrintWriter out = new PrintWriter(System.out);

        final String[] sl = s.split(" ");
        int N = Integer.parseInt(sl[0]);

        pf = new HashMap<>();

        for (int i = 2; i < N + 1; i++) primeFactor(i);

        int ans = f(75) + f(25) * (f(3) - 1)
            + f(15) * (f(5) - 1)
            + f(5) * (f(5) - 1) * (f(3) - 2) / 2;

        out.println(ans);

        out.flush();
    }
}