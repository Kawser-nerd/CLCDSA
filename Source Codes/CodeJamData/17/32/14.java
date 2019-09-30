package gcj2017.r1c;

import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Parents {
    
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        String name = "gcj2017/r1c/B-large";
        Scanner s = new Scanner(new File(name + ".in"));
        int count = s.nextInt();
        out = new PrintWriter(new BufferedWriter(new FileWriter(name + ".out")));
        //out = new PrintWriter(System.out);
        for (int ii = 1; ii <= count; ii++) {
            out.print("Case #" + ii + ": ");
            int an = s.nextInt();
            int bn = s.nextInt();
            List<D> aj = new ArrayList<>();
            List<D> bj = new ArrayList<>();
            for(int i=0; i<an; i++) {
                aj.add(new D(1, s.nextInt(), s.nextInt()));
            }
            for(int i=0; i<bn; i++) {
                bj.add(new D(2, s.nextInt(), s.nextInt()));
            }
            int res = solve(an, bn, aj, bj);
            out.print(res);
            out.println();          
        }
        out.close();
    }

    static int solve(int an, int bn, List<D> aj, List<D> bj) {
        List<D> jobs = new ArrayList<>();
        int n = an + bn;
        jobs.addAll(aj);
        jobs.addAll(bj);
        jobs.sort(new Comparator<D>(){
            @Override
            public int compare(D o1, D o2){
                return o1.start - o2.start;
            };
        });
        int at = 0;
        int bt = 0;
        int c = 0;
        int flex = 0;
        List<D> same = new ArrayList<>();
        for(int i=0; i<n ;i++) {
            D d = jobs.get(i);
            if(d.c == 1) {
                at += d.l;
            } else {
                bt += d.l;
            }
            D pre = jobs.get((i - 1 + n) % n);
            if(pre.c == d.c) {
                c += 2;
                same.add(new D(d.c, pre.end, d.start));
            } else {
                c += 1;
                flex += (d.start - pre.end + 1440) % 1440;
            }
        }
        int m = same.size();
        same.sort(new Comparator<D>(){
            @Override
            public int compare(D o1, D o2){
                return o1.l - o2.l;
            };
        });
        for(int i=0; i<m; i++) {
            D d = same.get(i);
            if(d.c == 1) {
                if(at + d.l <= 720) {
                    at += d.l;
                    c -= 2;
                }
            }
            if(d.c == 2) {
                if(bt + d.l <= 720) {
                    bt += d.l;
                    c -= 2;
                }
            }
        }


        return c;
    }

    static class D {
        public int c;
        public int start;
        public int end;
        public int l;
        public D(int c, int start, int end) {
            this.c = c;
            this.start = start;
            this.end = end;
            this.l = (end - start + 1440) % 1440;
        }
    }

}
