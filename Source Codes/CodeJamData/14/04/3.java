package exoD;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author jean
 */
public class ExoD {

    public static void main(String[] args) {


        String base = "/home/jean/gcj2014/q/ExoD/";
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
            Logger.getLogger(ExoD.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    private static void test(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        double Naomi[] = new double[N];
        double Ken[] = new double[N];
        
        for(int i=0; i<N; i++) {
            Naomi[i] = sc.nextDouble();
        }

        for(int i=0; i<N; i++) {
            Ken[i] = sc.nextDouble();
        }

        Arrays.sort(Naomi);
        Arrays.sort(Ken);
        double[] Ken2 = new double[N];
        
        for(int i=0; i<N; i++) {
            Ken2[i] = Ken[i];
        }
        
        
        //optimal war
        int c = 0;
        for(int i=0;i<N;i++) {
            double d = Naomi[i];
            int j;
            for(j=0;j<N;j++) {
                if(Ken[j]>d) {
                    Ken[j] = 0.0;
                    break;
                }
            }
            if(j == N ) {
                c++;
                //Play smallest
                for(j=0;j<N;j++) {
                    if(Ken[j]>0.0) {
                        Ken[j] = 0.0;
                        break;
                    }
                }  
            }
        }
        
        // deceitful war

        int c2 = 0;
        for(int i=0;i<N;i++) {
            double d = Ken2[i];
            int j;
            for(j=0;j<N;j++) {
                if(Naomi[j]>d) {
                    Naomi[j] = 0.0;
                    break;
                }
            }
            if(j == N ) {
                c2++;
                //Play smallest
                for(j=0;j<N;j++) {
                    if(Naomi[j]>0.0) {
                        Naomi[j] = 0.0;
                        break;
                    }
                }  
            }
        }        
        
        pw.print((N-c2) + " " + c);
        
    }


}
