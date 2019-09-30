import java.util.*;

class Main{
    static int n;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        n = Integer.parseInt(sc.next());
        long[] h = new long[n];
        long[] s = new long[n];
        for(int i=0;i<n;i++){
            h[i] = Long.parseLong(sc.next());
            s[i] = Long.parseLong(sc.next());
        }
        // Calculating the penalty: the biggest h[i]+s[i]*t[i] (t[i] is the time that it live)
        // We want to minimize this value among all (typical minimize max-value problem)
        long hi = 0;
        long lo = 0;
        for(int i=0;i<n;i++){
            hi = Math.max(hi,h[i]+s[i]*(n-1));
            lo = Math.max(lo,h[i]-1);
        }
        long mid;
        while(hi-lo>1){
            mid = (hi+lo)/2;
            if(check(h,s,mid)) hi=mid;
            else lo = mid;
        }
        System.out.println(hi);

    }
    // rec[i] records how many balloons need to be shot with a t[i]<=i;
    static boolean check(long[] h, long[] s, long target){
        int[] rec = new int[n];
        int cur;
        for(int i=0;i<n;i++){
            if(target<h[i]) return false;
            cur = (int) Math.min(n-1,(target-h[i])/s[i]);
            rec[cur]++;
            if(rec[cur]>cur+1) return false;
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += rec[i];
            if(sum>i+1) return false;
        }
        return true;
    }
}