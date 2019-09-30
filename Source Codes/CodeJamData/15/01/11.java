package de.kleberhoff.googlecodejam.quali_2015;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


/**
 * 
 * @author ralf
 *
 */
public class A_StandingOvation {
    
    int[] shynessDistribution;
    
    public A_StandingOvation(Scanner input) {
        int n = input.nextInt();
        shynessDistribution = new int[n+1];
        String str = input.next();
        for (int i=0; i<str.length(); i++) {
            shynessDistribution[i] = Integer.parseInt(str.substring(i, i+1));
        }
    }
    
    public long solve() {
        int standing = 0;
        int addition = 0;
        for (int shyness=0; shyness<shynessDistribution.length; shyness++) {
            int missing = shyness - standing;
            if (missing > 0) {
                addition += missing;
                standing += missing;
            }
            standing += shynessDistribution[shyness];
        }
        return addition;
    }

    public static void main(String[] args) throws IOException {
        long start = System.currentTimeMillis();
        Scanner scanner = new Scanner(new File("D:/Codejam/2015-Q/A.in"));
        PrintWriter writer = new PrintWriter("D:/Codejam/2015-Q/A.out");
        int nTests = scanner.nextInt();
        for (int i=1; i<=nTests; i++) {
            A_StandingOvation task = new A_StandingOvation(scanner);
            StringBuilder builder = new StringBuilder();
            long result = task.solve();
            builder.append("Case #" + i + ": ").append(result);
            
            writer.println(builder);
            System.out.println(builder);
        }
        scanner.close();
        writer.close();
        long finish = System.currentTimeMillis();
        System.out.println("Time=" + (finish - start) + "ms");
    }
    
}
