import java.util.*;
import java.io.*;

import static java.lang.System.in;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt(), K=sc.nextInt(), Q=sc.nextInt();
        int[] a = new int[n];
        for(int i=0;i<n;i++) a[i]=sc.nextInt();
        HashSet<Integer> vis = new HashSet<>();
        PriorityQueue<Integer> small = new PriorityQueue<>(), big = new PriorityQueue<>();
        int ans = Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            if(!vis.add(a[i])) continue;
            big.clear();
            int left=0;
            while(left<n){
                if(a[left]<a[i]) {
                    left++;
                    continue;
                }
                small.clear();
                while(left<n&&a[left]>=a[i]){
                    small.add(a[left++]);
                }
                while(small.size()>=K) big.add(small.poll());
            }
            if(big.size()<Q) continue;
            for(int j=1;j<Q;j++) big.poll();
            ans = Math.min(ans,big.peek()-a[i]);
        }
        System.out.println(ans);
    }
}