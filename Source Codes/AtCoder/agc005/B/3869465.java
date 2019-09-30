import java.util.*;
import java.io.*;

import static java.lang.System.in;

public class Main {
    ArrayList<Integer>[] graph;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n+1];
        int[] pos = new int[n+1];
        for(int i=1;i<=n;i++) {
            a[i]=sc.nextInt();
            pos[a[i]] = i;
        }
        TreeSet<Integer> ts = new TreeSet<>();
        ts.add(0); ts.add(n+1);
        long ans = 0;
        for(int i=1;i<=n;i++){
            int lo = ts.lower(pos[i]);
            int hi = ts.higher(pos[i]);
            ans += ((long)(pos[i]-lo))*((long)(hi-pos[i]))*i;
            ts.add(pos[i]);
        }
        System.out.println(ans);
    }
}