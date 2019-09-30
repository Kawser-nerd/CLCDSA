import java.io.IOException;

import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.io.PrintWriter;

import java.util.ArrayList;

@SuppressWarnings("unchecked")
public class Main {
    static final char c = 'a';

    static ArrayList<String> ans;
    static int N;

    static void f(int i, char x, StringBuilder sb) {
        if (N - 1 < i) ans.add(sb.toString());

        boolean flg = true;

        if (N - 1 < i || c + 2 < x) {
            while (sb.length() != 0) {
                char t = sb.charAt(sb.length() - 1);
                sb.setLength(sb.length() - 1);
                if (t < c + 2) {
                    flg = false;
                    x = (char)(t + 1);
                    break;
                }
            }

            if (flg) return;
        }

        sb.append(x);
        f(sb.length(), flg ? x : c, sb);
    }

    public static void main(String[] args) throws IOException {
        final String s;

        try (
            BufferedReader reader = new BufferedReader(
                new InputStreamReader(System.in))) {
            s = reader.readLine();
        }

        PrintWriter out = new PrintWriter(System.out);

        N = Integer.parseInt(s);

        ans = new ArrayList<>();

        StringBuilder sb = new StringBuilder();

        f(sb.length(), c, sb);

        for (String str : ans)  out.println(str);

        out.flush();
    }
}