import java.io.IOException;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        try (
            BufferedReader reader = new BufferedReader(
                new InputStreamReader(System.in))) {
            String s = reader.readLine();

            int prelen = s.length();
            boolean flg = true;

            while (0 < s.length()) {
                s = s.replaceAll("ch$", "");
                s = s.replaceAll("o$", "");
                s = s.replaceAll("k$", "");
                s = s.replaceAll("u$", "");

                if (prelen == s.length()) {
                    flg = false;
                    break;
                }

                prelen = s.length();
            }

            System.out.println(flg ? "YES" : "NO");
        }
    }
}