/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package codejam2c;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new FileReader("c-small.in"));
        PrintWriter out = new PrintWriter(new FileWriter("c-small-out.out"));

        final long M = 1000000007;
        int T = in.nextInt();
        for(int x=1; x<=T; x++){
            int n = in.nextInt(), m = in.nextInt(), X= in.nextInt(), Y= in.nextInt(), Z= in.nextInt();
            int i, j;
            int[] a = new int[n], A = new int[m];
            long[] nr = new long[n];
            long S = 0;
            for(i = 0; i < m; i++){
                A[i] = in.nextInt();
            }
            for(i = 0; i<n; i++){
                a[i] = A[i % m];
                A[i % m] = (int)(((long)((long)X * A[i % m] + (long)Y * (i + 1))) % (long)Z);
            }
            nr[0] = 1; S = 1;
            for(i = 1; i < n; i++){
                nr[i] = 1;
                for(j = 0; j<i; j++)
                    if(a[j] < a[i]){
                        nr[i] += nr[j];
                        nr[i] %= M;
                    }
               S += nr[i];
               S %= M;
            }
          out.printf("Case #%d: %d%n", x, S);      
        }
        in.close();
        out.close();
               
    }

}
