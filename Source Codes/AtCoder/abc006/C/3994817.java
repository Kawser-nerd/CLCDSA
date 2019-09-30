import java.io.IOException;

import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.io.PrintWriter;

@SuppressWarnings("unchecked")
public class Main {
    public static void main(String[] args) throws IOException {
        final String s;

        try (
            BufferedReader reader = new BufferedReader(
                new InputStreamReader(System.in))) {
            s = reader.readLine();
        }

        PrintWriter out = new PrintWriter(System.out);

        final String[] sl = s.split(" ");
        long N = Long.parseLong(sl[0]);
        long M = Long.parseLong(sl[1]);

        long adult = -1;
        long old = -1;
        long baby = -1;

        boolean flg = false;

        // ???? ???
        for (long i = 0; i < N + 1; i++) {
            // ?? 0 1
            for (long j = 0; j < 2; j++) {
                if (N - i - j < 0) continue;

                if (M == 2 * (N - i - j) + 3 * j + 4 * i) {
                    flg = true;
                    adult = N - i - j;
                    old = j;
                    baby = i;
                    break;
                }
            }

            if (flg) break;
        }

        out.println(adult + " " + old + " " + baby);

        out.flush();
    }
}