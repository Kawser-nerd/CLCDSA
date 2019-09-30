package gcj2015.r1;

import java.io.*;
import java.util.Scanner;

public class Haircut {

    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        String name = "gcj2015/r1/B-large";
        Scanner s = new Scanner(new File(name + ".in"));
        int count = s.nextInt();
        out = new PrintWriter(new BufferedWriter(new FileWriter(name + ".out")));
        // out = new PrintWriter(System.out);
        for (int cc = 1; cc <= count; cc++) {
            out.print("Case #" + cc + ": ");
            int b = s.nextInt();
            int n = s.nextInt();
            int[] m = new int[b];
            for(int i=0; i<b; i++) {
                m[i] = s.nextInt();
            }
            int res = solve(b, n, m);
            out.print(res);
            out.println();
        }
        out.close();
    }

    static int solve(int b, int n ,int[] m) {
        long l = 0;
        long r = 100000l * n + 1;
        long mid;
        while(true) {
            mid = (l + r) / 2;
            long num = num(b, m, mid);
            if(num < n) {
                l = mid;
            } else {
                r = mid;
            }
            if(r - mid == 1) break;
        }
        // out.print(mid + " ");
        int rem = n - (int)num(b, m, mid);
        for(int i=0; i<b; i++) {
            if(mid % m[i] == 0) {
                rem--;
            }
            if(rem == 0) return i+1;
        }
        return -1;
    }

    static long num(int b, int[] m, long t) {
//        out.print(t + ":");
        long res = 0;
        for(int mm : m) {
            res += (t + mm -1 ) / mm;
        }
//        out.print(res + " ");
        return res;
    }


}
