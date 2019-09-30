package gcj2017.r1c;

import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

public class Training {
    
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        String name = "gcj2017/r1c/C-small-1";
        Scanner s = new Scanner(new File(name + ".in"));
        int count = s.nextInt();
        out = new PrintWriter(new BufferedWriter(new FileWriter(name + ".out")));
        //out = new PrintWriter(System.out);
        for (int ii = 1; ii <= count; ii++) {
            out.print("Case #" + ii + ": ");
            int n = s.nextInt();
            int k = s.nextInt();
            double u = s.nextDouble();
            double[] p = new double[n];
            for(int i=0 ; i<n; i++) {
                p[i] = s.nextDouble();
            }
            double res = solve(n, k, u, p);
            out.print(String.format("%.8f", res));
            out.println();          
        }
        out.close();
    }

    static double solve(int n, int k, double u, double[] p) {
        Arrays.sort(p);
        while(u > 0.000000001) {
            double min = p[0];
            int ni = n;
            double np = 1;
            for(int i=1; i<n; i++) {
                if(p[i] == min) {
                    continue;
                }
                np = p[i];
                ni = i;
                break;
            }
            if(ni * (np - min) <= u) {
                for(int i=0; i<ni; i++) {
                    p[i] = np;
                }
                u -= ni * (np - min);
            } else {
                double d = u / ni;
                for(int i=0; i<ni; i++) {
                    p[i] += d;
                }
                u = 0;
            }
        }

        double res = 1;
        for(int i=0; i<n; i++) {
            res *= p[i];
        }
        return res;
    }

}
