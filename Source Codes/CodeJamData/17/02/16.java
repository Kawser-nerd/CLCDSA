package year2017.qualification;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class TidyNumbers {
    
    public static void main(String[] args) throws Exception {
        File inputFile = new File("B-large.in");
        Scanner in = new Scanner(inputFile);
        File outputFile = new File("output.txt");
        PrintWriter out = new PrintWriter(outputFile);

        int T = in.nextInt();
        for (int t=0; t<T; t++) {
            char[] c = in.next().toCharArray();
            for (int i=c.length-2; i>=0; i--) {
                if (c[i] > c[i+1]) {
                    c[i]--;
                    for (int j=i+1; j<c.length; j++) {
                        c[j] = '9';
                    }
                }
            }
            int offset = (c[0] == '0') ? 1 : 0;
            String answer = new String(c, offset, c.length - offset);
            
            out.println("Case #"+(t+1)+": "+answer);
        }

        out.close();
    }
    
}
