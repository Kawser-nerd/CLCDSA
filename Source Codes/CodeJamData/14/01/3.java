package exoA;

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
public class ExoA {

    public static void main(String[] args) {


        String base = "/home/jean/gcj2014/q/ExoA/";
        String input = base + "s1.in";
        String output = base + "s1.out";

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
            Logger.getLogger(ExoA.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    private static void test(Scanner sc, PrintWriter pw) {
        int t1[][] = new int[4][4];
        int t2[][] = new int[4][4];
   
        int a1 = sc.nextInt();
        sc.nextLine();     
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                t1[i][j] = sc.nextInt();
            }
            sc.nextLine();
        }
        
        int a2 = sc.nextInt();
        sc.nextLine();     
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                t2[i][j] = sc.nextInt();
            }
            sc.nextLine();
        }
        
        int c=0;
        int r=0;
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                if(t1[a1-1][i] == t2[a2-1][j]) {
                    c++;
                    r = t1[a1-1][i];
                }
            }
        }
        
        if(c == 1) {
            pw.print(r);
        } else if(c == 0) {
            pw.print("Volunteer cheated!");
        } else {
            pw.print("Bad magician!");
        }
    }


}
