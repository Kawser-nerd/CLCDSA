import java.io.IOException;

import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.io.PrintWriter;

@SuppressWarnings("unchecked")
public class Main {
    static final String[] scales =
    {"Do", "Re", "Mi", "Fa", "So", "La", "Si"};

    static final char[] keys =
    {'W','B','W','B','W','W','B','W','B','W','B','W'};

    public static void main(String[] args) throws IOException {
        final String S;

        try (
            BufferedReader reader = new BufferedReader(
                new InputStreamReader(System.in))) {
            S = reader.readLine();
        }

        PrintWriter out = new PrintWriter(System.out);

        for (int i = 0; i < scales.length; i++) {
            int idx = 0;
            int cnt = 0;

            for (char c : keys) {
                if (c == S.charAt(0)) cnt++;
                if (i < cnt) break;
                idx++;
            }

            boolean flg = true;
            for (int j = 0; j < S.length(); j++) {
                char c = S.charAt(j);

                if (keys.length <= idx) idx -= keys.length;

                if (c != keys[idx]) {
                    flg = false;
                    break;
                }

                idx++;
            }

            if (flg) {
            	out.println(scales[i]);
            	break;
            }
        }

        out.flush();
    }
}