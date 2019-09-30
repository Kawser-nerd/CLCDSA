package C;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class CandySplitting {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("src/C/C-large.in"));
        String s = reader.readLine();
        int t = Integer.parseInt(s);
        PrintWriter writer = new PrintWriter("src/C/output.txt");
        for (int i = 0; i < t; i++) {
            s = reader.readLine();
            int n = Integer.parseInt(s);
            s = reader.readLine();
            String[] ss = s.split("\\s+");
            int sum = 0;
            int sum2 = 0;
            int min = Integer.MAX_VALUE;
            for (int j = 0; j < n; j++) {
                int c = Integer.parseInt(ss[j]);
                min = Math.min(min, c);
                sum += c;
                sum2 ^= c;
            }
            writer.print("Case #" + (i + 1) + ": ");
            if (sum2 != 0) {
                writer.println("NO");
            } else {
                writer.println(sum - min);
            }
        }
        writer.close();
    }
}
