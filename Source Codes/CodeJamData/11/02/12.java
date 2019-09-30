package B;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class Magicka {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("src/B/B-large.in"));
        String s = reader.readLine();
        int t = Integer.parseInt(s);
        PrintWriter writer = new PrintWriter("src/B/output.txt");
        for (int i = 0; i < t; i++) {
            s = reader.readLine();
            String[] ss = s.split("\\s+");
            int c = Integer.parseInt(ss[0]);
            char[][] combine = new char[256][256];
            for (int j = 0; j < c; j++) {
                s = ss[j + 1];
                combine[s.charAt(0)][s.charAt(1)] = s.charAt(2);
                combine[s.charAt(1)][s.charAt(0)] = s.charAt(2);
            }
            int d = Integer.parseInt(ss[c + 1]);
            boolean[][] opposed = new boolean[256][256];
            for (int j = 0; j < d; j++) {
                s = ss[j + c + 2];
                opposed[s.charAt(0)][s.charAt(1)] = true;
                opposed[s.charAt(1)][s.charAt(0)] = true;
            }
            int n = Integer.parseInt(ss[c + d + 2]);
            s = ss[c + d + 3];
            char[] result = new char[200];
            int len = 0;
            for (int j = 0; j < n; j++) {
                char ch = s.charAt(j);
                char pr = 0;
                if (len > 0) {
                    pr = result[len - 1];
                }
                char r = combine[ch][pr];
                if (r != 0) {
                    ch = r;
                    len--;
                }
                result[len++] = ch;
                for (int k = 0; k < len - 1; k++) {
                    if (opposed[ch][result[k]]) {
                        len = 0;
                        break;
                    }
                }
            }
            writer.print("Case #" + (i + 1) + ": [");
            for (int j = 0; j < len; j++) {
                if (j > 0) {
                    writer.print(", ");
                }
                writer.print(result[j]);
            }
            writer.println("]");
        }
        writer.close();
    }
}
