package year2016.round1a;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class TheLastWord {
    
    public static void main(String[] args) throws Exception {
        File inputFile = new File("A-large.in");
        Scanner in = new Scanner(inputFile);
        File outputFile = new File("output.txt");
        PrintWriter out = new PrintWriter(outputFile);

        int T = in.nextInt();
        for (int t=0; t<T; t++) {
            String s = in.next();
            String answer = solve(s);
            
            out.println("Case #"+(t+1)+": " + answer);
        }

        out.close();
    }

    static String solve(String s) {
        int length = s.length();
        if (length == 0) {
            return "";
        } else {
            char max = s.charAt(0);
            for (char c : s.toCharArray()) {
                max = (char)Math.max(c, max);
            }
            char last = s.charAt(length-1);
            if (max == last) {
                return last + solve(s.substring(0, length-1));
            } else {
                return solve(s.substring(0, length-1)) + last;
            }
        }
    }
    
}
