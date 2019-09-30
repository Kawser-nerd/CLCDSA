package exo2;

import exo1.TicTacToeTomek;
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
public class LawnMower {

    public static void main(String[] args) {
        String base = "/home/jean/gcj2013/lawnmower/";
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
            Logger.getLogger(TicTacToeTomek.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    private static void test(Scanner sc, PrintWriter pw) {
        final int N = sc.nextInt();
        final int M = sc.nextInt();
        int[][] table = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                table[i][j] = sc.nextInt();
            }
        }

        // Idea : every a_ij must be either the max in their row, or column. (and it's enough)
        // (then we can mow from the biggest a_ij to the smallest, along either
        // the row or colomn where they are max, to make them reach their height)
        // So we computes the max of every lines and column.

        int[] maxr = new int[N];
        int[] maxc = new int[M];

        for (int i = 0; i < N; i++) {
            maxr[i] = 0;
            for (int j = 0; j < M; j++) {
                if (table[i][j] > maxr[i]) {
                    maxr[i] = table[i][j];
                }
            }
        }

        for (int i = 0; i < M; i++) {
            maxc[i] = 0;
            for (int j = 0; j < N; j++) {
                if (table[j][i] > maxc[i]) {
                    maxc[i] = table[j][i];
                }
            }
        }

        // Finally, if any a_ij is not one of the maxes, we return false.
        
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                int t = table[i][j];
                if(t != maxr[i] && t != maxc[j]) {
                    pw.print("NO");
                    return;
                }
            }
        }
        
        pw.print("YES");
        

    }
}