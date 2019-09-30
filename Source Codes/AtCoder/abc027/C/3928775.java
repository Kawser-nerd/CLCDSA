import java.io.IOException;

import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.io.PrintWriter;

@SuppressWarnings("unchecked")
public class Main {
    static final String Takahashi = "Takahashi";
    static final String Aoki = "Aoki";

    static long N;

    static boolean odd;

    // ???? true
    static boolean f() {
        // ??
        boolean turn = true;

        long num = 1;

        while (num <= N) {
            // ?? ?? ???????? ???
            // ?? ?? ???????? ????
            if (turn) {
                if (odd) num = 2 * num+ 1;
                else num = 2 * num;
            } else {
                if (odd) num = 2 * num;
                else num = 2 * num + 1;
            }

            turn = !turn;
        }

        boolean flg = true;
        // ???????????? ???
        if (!turn) flg = false;
        return flg;
    }

    public static void main(String[] args) throws IOException {
        final String s;

        try (
            BufferedReader reader = new BufferedReader(
                new InputStreamReader(System.in))) {
            s = reader.readLine();
        }

        PrintWriter out = new PrintWriter(System.out);

        N = Long.parseLong(s);

        long depth = 0;

        for (long i = N; 0 < i; i /= 2) depth++;

        odd = depth % 2 == 1;

        if (f()) out.println(Takahashi);
            else out.println(Aoki);

        out.flush();
    }
}