package year2016.round1a;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class RankAndFile {
    
    public static void main(String[] args) throws Exception {
        File inputFile = new File("B-large.in");
        Scanner in = new Scanner(inputFile);
        File outputFile = new File("output.txt");
        PrintWriter out = new PrintWriter(outputFile);

        int T = in.nextInt();
        for (int t=0; t<T; t++) {
            int N = in.nextInt();
            int[] stat = new int[2501];
            for (int i=0; i<N*(2*N-1); i++) {
                int height = in.nextInt();
                stat[height]++;
            }
            StringBuilder output = new StringBuilder();
            for (int i=1; i<=2500; i++) {
                if (stat[i]%2 == 1) {
                    output.append(' ').append(i);
                }
            }
            
            out.println("Case #"+(t+1)+":" + output);
        }

        out.close();
    }
    
}
