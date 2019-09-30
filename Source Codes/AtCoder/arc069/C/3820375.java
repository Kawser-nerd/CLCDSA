import java.util.*;
import java.io.*;

import static java.lang.System.in;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[n+1];
        for(int i=1;i<=n;i++) a[i] = sc.nextLong();
        long[] left = new long[n+1];
        for(int i=1;i<=n;i++) left[i] = Math.max(left[i-1],a[i]);
        PriorityQueue<Long> pq = new PriorityQueue<>(10,Collections.reverseOrder());
        long[] ans = new long[n+1];
        long hi = left[n];
        long cnt = 0;
        for(int i=n;i>0;i--){
            if(a[i]<=left[i-1]){
                pq.add(a[i]);
                continue;
            }
            long lo = left[i-1];
            cnt++;
            ans[i] += cnt*(hi-lo);
            while(pq.size()>0&&pq.peek()>lo){
                ans[i] += pq.poll()-lo;
                cnt++;
            }
            hi = lo;
        }
        PrintWriter out = new PrintWriter(System.out);
        for(int i=1;i<=n;i++) out.println(ans[i]);
        out.flush();
    }
}