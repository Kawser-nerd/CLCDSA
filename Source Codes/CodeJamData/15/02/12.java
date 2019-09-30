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
public class B_Pancakes {
    
    int[] pancakes;
    int highest;
    
    public B_Pancakes(Scanner input) {
        int d = input.nextInt();
        pancakes = new int[d];
        highest = 0;
        for (int i=0; i<d; i++) {
            int h = input.nextInt();
            if (h > highest) {
                highest = h;
            }
            pancakes[i] = h;
        }
    }
    
    public long solve() {
        int bestSteps = highest;
        for (int rem=1; rem<highest; rem++) {
            int splitSteps = 0;
            for (int h : pancakes) {
                int steps = (h-1) / rem;
                splitSteps += steps;
            }
            int cost = splitSteps + rem;
            if (cost < bestSteps) {
                bestSteps = cost;
            }
        }
        return bestSteps;
    }

    public static void main(String[] args) throws IOException {
        long start = System.currentTimeMillis();
        Scanner scanner = new Scanner(new File("D:/Codejam/2015-Q/B.in"));
        PrintWriter writer = new PrintWriter("D:/Codejam/2015-Q/B.out");
        int nTests = scanner.nextInt();
        for (int i=1; i<=nTests; i++) {
            B_Pancakes task = new B_Pancakes(scanner);
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
