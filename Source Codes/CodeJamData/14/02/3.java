package exoB;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author jean
 */
public class ExoB {

    public static void main(String[] args) {


        String base = "/home/jean/gcj2014/q/ExoB/";
        String input = base + "b1.in";
        String output = base + "b1.out";

        try {
            Scanner sc = new Scanner(new FileReader(input));
            PrintWriter pw = new PrintWriter(output);

            int n = sc.nextInt();
            sc.nextLine();
            for (int c = 0; c < n; c++) {
                System.out.println("Test case " + (c + 1) + "...");
                pw.print("Case #" + (c + 1) + ": ");
                test(sc, pw);
                pw.println();
            }
            pw.println();
            pw.flush();
            pw.close();
            sc.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(ExoB.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    private static void test(Scanner sc, PrintWriter pw) {
        double C = sc.nextDouble();
        double F = sc.nextDouble();
        double X = sc.nextDouble();
        
        double r = 2.0;
        double t = 0.0;
        
        while(X/r > C/r + X/(r + F)) {
            t = t + C/r;
            r += F;
        }
        
        t = t + X /r;
        
        pw.print(t);
    }


}
