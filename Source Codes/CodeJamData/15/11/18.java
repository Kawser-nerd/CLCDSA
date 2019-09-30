package gcj2015.r1;

import java.io.*;
import java.util.Scanner;

public class Mushroom {

    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        String name = "gcj2015/r1/A-large";
        Scanner s = new Scanner(new File(name + ".in"));
        int count = s.nextInt();
        out = new PrintWriter(new BufferedWriter(new FileWriter(name + ".out")));
        //out = new PrintWriter(System.out);
        for (int cc = 1; cc <= count; cc++) {
            out.print("Case #" + cc + ": ");
            int n = s.nextInt();
            int[] a = new int[n];
            for(int i=0; i<n; i++) {
                a[i] = s.nextInt();
            }
            int res1 = solve1(n, a);
            int res2 = solve2(n, a);
            out.print(res1);
            out.print(' ');
            out.print(res2);
            out.println();
        }
        out.close();
    }

    static int solve1(int n, int[] a) {
        int res = 0;
        for(int i=0; i<n-1; i++) {
            res += Math.max(a[i]-a[i+1], 0);
        }
        return res;
    }
    static int solve2(int n, int[] a) {
        int res = 0;
        int max = 0;
        for(int i=0; i<n-1; i++) {
            max = Math.max(a[i]-a[i+1], max);
        }
        for(int i=0; i<n-1; i++) {
            res += Math.min(a[i], max);
        }
        return res;
    }

}
