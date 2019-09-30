import java.io.IOException;

import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.io.PrintWriter;

import java.util.ArrayList;

class Pair {
    long first;
    long second;

    Pair (long first, long second) {
        this.first = first;
        this.second = second;
    }
}

@SuppressWarnings("unchecked")
public class Main {
    // ??
    static void divisor(ArrayList<Pair> div, long N) {
        long n;
        long i = 1;

        n = N;

        while (i <= Math.sqrt(n)) {
            if (n % i == 0) div.add(new Pair(i, n / i));
            i++;
        }
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
        int M = Integer.parseInt(sl[1]);

        ArrayList<Pair> div = new ArrayList<>();
        divisor(div, M);

        long MAX = M / N + 1;

        long ans = 0;

        for (Pair p : div) {
            long first = p.first;
            long second = p.second;

            if (first < MAX && ans < first) ans = first;
            if (second < MAX && ans < second) ans = second;
        }

        out.println(ans);

        out.flush();
    }
}