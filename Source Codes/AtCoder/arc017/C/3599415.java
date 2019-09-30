import java.util.*;
import java.io.*;

import static java.lang.System.in;

public class Main {
    static long R,B,x,y;
    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int X = sc.nextInt();
        int[] w = new int[n];
        for(int i=0;i<n;i++) w[i] = sc.nextInt();
        long ans = help(w,X);
        System.out.println(ans);
    }
    static long help(int[] w, int X){
        int n = w.length;
        if(n==1){
            return w[0]==X?1:0;
        }
        int ans = 0;
        int p = n/2;
        HashMap<Integer, Integer> dic = getDic(Arrays.copyOfRange(w,p,n));
        int[] first = Arrays.copyOfRange(w,0,p);
        for(int i=0;i<(1<<p);i++){
            int cur = getSum(first,i);
            ans += dic.getOrDefault(X-cur,0);
        }
        return ans;
    }
    static HashMap<Integer,Integer> getDic(int[] a){
        int q = a.length;
        HashMap<Integer,Integer> ans = new HashMap<>();
        for(int i=0;i<(1<<q);i++){
            int cur = getSum(a,i);
            int val = ans.getOrDefault(cur,0)+1;
            ans.put(cur,val);
        }
        return ans;
    }
    static int getSum(int[] a, int mask){
        int sum = 0;
        for(int i=0;i<a.length;i++){
            if((mask&(1<<i))>0) sum += a[i];
        }
        return sum;
    }
}