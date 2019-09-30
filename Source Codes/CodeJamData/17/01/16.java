package year2017.qualification;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class OversizedPancakeFlipper {
    
    public static void main(String[] args) throws Exception {
        File inputFile = new File("A-large.in");
        Scanner in = new Scanner(inputFile);
        File outputFile = new File("output.txt");
        PrintWriter out = new PrintWriter(outputFile);

        int T = in.nextInt();
        for (int t=0; t<T; t++) {
            char[] c = in.next().toCharArray();
            int K = in.nextInt();
            int count = 0;
            for (int i=0; i<=c.length-K; i++) {
                if (c[i] == '-') {
                    count++;
                    for (int k=0; k<K; k++) {
                        c[i+k] = (c[i+k] == '-') ? '+' : '-';
                    }
                }
            }
            for (int i=c.length-K+1; i<c.length; i++) {
                if (c[i] == '-') {
                    count = -1;
                }
            }
            
            out.println("Case #"+(t+1)+": " + ((count == -1) ? "IMPOSSIBLE" : count));
        }

        out.close();
    }
    
}
