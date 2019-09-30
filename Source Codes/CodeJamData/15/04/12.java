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
public class D_Omino {
    
    int x;
    int r;
    int c;
    
    
    
    public D_Omino(Scanner input) {
        x = input.nextInt();
        r = input.nextInt();
        c = input.nextInt();
    }
    
    public boolean solve() {
        if (x == 1) {
            return true;
        }
        if (x >= 7) {
            return false;
        }
        if ((r*c) % x != 0) {
            return false;
        }
        if (!willFit()) {
            return false;
        }
        if (specialFailure()) {
            return false;
        }
        return true;
    }
    
    boolean willFit() {
        int d1 = Math.min(r, c);
        int d2 = Math.max(r, c);
        for (int w=1,h=x; w<=h; w++,h--) {
            if (w > d1 || h > d2) {
                return false;
            }
        }
        return true;
    }
    
    boolean specialFailure() {
        int d1 = Math.min(r, c);
        int d2 = Math.max(r, c);
        switch(x) {
        case 4:
            if (d1 == 2) {
                return true;
            }
            break;
        case 5:
            if (d1 == 3 && d2 == 5) {
                return true;
            }
            break;
        case 6:
            if (d1 == 3) {
                return true;
            }
            break;
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        long start = System.currentTimeMillis();
        Scanner scanner = new Scanner(new File("D:/Codejam/2015-Q/D.in"));
        PrintWriter writer = new PrintWriter("D:/Codejam/2015-Q/D.out");
        int nTests = scanner.nextInt();
        for (int i=1; i<=nTests; i++) {
            D_Omino task = new D_Omino(scanner);
            StringBuilder builder = new StringBuilder();
            boolean result = task.solve();
            builder.append("Case #" + i + ": ").append(result ? "GABRIEL" : "RICHARD");
            
            writer.println(builder);
            System.out.println(builder);
        }
        scanner.close();
        writer.close();
        long finish = System.currentTimeMillis();
        System.out.println("Time=" + (finish - start) + "ms");
    }
    
}
