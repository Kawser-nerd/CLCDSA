package year2017.round1b;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class CruiseControl {
    
    public static void main(String[] args) throws Exception {
        File inputFile = new File("A-large.in");
        Scanner in = new Scanner(inputFile);
        File outputFile = new File("output.txt");
        PrintWriter out = new PrintWriter(outputFile);

        int T = in.nextInt();
        for (int t=0; t<T; t++) {
            double D = in.nextDouble();
            int N = in.nextInt();
            double maxTime = 0;
            for (int n=0; n<N; n++) {
                double K = in.nextDouble();
                double S = in.nextDouble();
                double time = (D-K)/S;
                maxTime = Math.max(time, maxTime);
            }
            double speed = D/maxTime;
            
            out.println("Case #"+(t+1)+": " + speed);
        }

        out.close();
    }
    
}
