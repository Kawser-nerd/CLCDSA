package gcj2017.r1c;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class Template {
    
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        String name = "gcj2017/r1c/A-large";
        Scanner s = new Scanner(new File(name + ".in"));
        int count = s.nextInt();
        out = new PrintWriter(new BufferedWriter(new FileWriter(name + ".out")));
        //out = new PrintWriter(System.out);
        for (int ii = 1; ii <= count; ii++) {
            out.print("Case #" + ii + ": ");
            int n = s.nextInt();
            int k = s.nextInt();
            ArrayList<P> list = new ArrayList();
            for(int i=0; i<n; i++) {
                list.add(new P(s.nextInt(), s.nextInt()));
            }
            double res = solve(n, k, list);
            out.print(String.format("%f", res));
            out.println();          
        }
        out.close();
    }

    static double solve(int n, int k, ArrayList<P> list) {
        list.sort(new Comparator<P>(){
            @Override
            public int compare(P o1, P o2) {
                return o1.r - o2.r;
            }
        });

        double max = 0;
        while(list.size() >= k) {
             P last = list.remove(list.size()-1);
             double a = Math.PI * last.r * last.r + last.side;
             ArrayList<P> rem = new ArrayList<>(list);
             rem.sort(new Comparator<P>(){
                 public int compare(P o1, P o2) {
                     double diff = o2.side - o1.side;
                     if(diff < 0) return -1;
                     if(diff > 0) return 1;
                     return 0;
                 }
             });
             for(int i=0; i<k-1; i++) {
                 a += rem.get(i).side;
             }
            max = Math.max(max, a);
        }
        return max;
    }

    public static class P {
        public int r;
        public double side;
        public P(int r, int h) {
            this.r = r;
            this.side = Math.PI * r * 2 * h;
        }

    }
}
