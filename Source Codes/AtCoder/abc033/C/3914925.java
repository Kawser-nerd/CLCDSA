import java.io.IOException;

import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.io.PrintWriter;

@SuppressWarnings("unchecked")
public class Main {
    static final char plus = '+';
    static final char multi = '*';

    public static void main(String[] args) throws IOException {
        final String S;

        try (
            BufferedReader reader = new BufferedReader(
                new InputStreamReader(System.in))) {
            S = reader.readLine();
        }

        PrintWriter out = new PrintWriter(System.out);

        int ans = 0;
        int i = 0;
        boolean flg = false;

        int num = 0;
        char symbol = ' ';

        int len = S.length();

        while (i < len) {
            num = Character.getNumericValue(S.charAt(i++));

            if (len - 2 < i) break;

            symbol = S.charAt(i++);

            if (symbol == plus) {
                if (!flg && num != 0) ans++;
                flg = false;
            } else {
                if (num == 0) flg = true;
            }
        }

        if (!flg && num != 0) ans++;

        out.println(ans);

        out.flush();
    }
}