package de.measite.gcj;

import java.io.IOException;
import java.io.InputStreamReader;
import java.io.LineNumberReader;
import java.util.regex.Pattern;

public class Main1 {

    public static void main(String[] args) {
        try {
            LineNumberReader lnr = new LineNumberReader(new InputStreamReader(
                System.in));
            String line[] = lnr.readLine().trim().split(" ");
//            final int l = Integer.parseInt(line[0]);
            final int d = Integer.parseInt(line[1]);
            final int n = Integer.parseInt(line[2]);
            String word[] = new String[d];
            for (int i = 0; i < d; i++) {
                word[i] = lnr.readLine().trim();
            }
            // 5000 * 500 - way better than 26^10
            for (int i = 1; i <= n; i++) {
                String m = lnr.readLine().trim().replace('(', '[').replace(')', ']');
                Pattern pattern = Pattern.compile(m);
                int count = 0;
                for (String w: word) {
                    if (pattern.matcher(w).matches()) {
                        count++;
                    }
                }
                System.out.println("Case #" + i + ": " + count);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
