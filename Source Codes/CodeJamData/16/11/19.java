import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.net.URL;


public class t {
    


    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(
                            new InputStreamReader(System.in));
        String tline = in.readLine();
        Scanner sc = new Scanner(tline);
        int t = sc.nextInt();

        for (int it = 1; it <= t; ++it) {
            pf("Case #%d:", it);

            String line = in.readLine();

            pf(" %s\n", solve(line.trim()));
        }
    }

    static String solve(String line) {
        if (line.length() == 0)
            return "";
        char heaviest = line.charAt(0);
        for (int i = 1; i < line.length(); ++i) {
            if (line.charAt(i) > heaviest)
                heaviest = line.charAt(i);
        }
        StringBuilder rr = new StringBuilder();
        StringBuilder sub = new StringBuilder();
        StringBuilder tail = new StringBuilder();
        boolean found_first = false;
        for (int i = 0; i < line.length(); ++i) {
            if (heaviest == line.charAt(i)) {
                rr.append(heaviest);
                found_first = true;
            } else {
                if (found_first) {
                    tail.append(line.charAt(i));
                } else {
                    sub.append(line.charAt(i));
                }
            }
        }
        rr.append(solve(sub.toString()));
        rr.append(tail);
        return rr.toString();
    }


    static void pf(String format, Object...os) {
        System.out.printf(format, os);
    }

}
