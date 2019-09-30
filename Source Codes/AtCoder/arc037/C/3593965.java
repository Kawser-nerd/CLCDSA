import java.util.*;

class Main{
    static int inf = Integer.MAX_VALUE;
    static int n,k;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        n = Integer.parseInt(sc.next());
        k = Integer.parseInt(sc.next());
        long[] hori = new long[n];
        long[] vert = new long[n];
        for(int i=0;i<n;i++) vert[i] = Long.parseLong(sc.next());
        for(int i=0;i<n;i++) hori[i] = Long.parseLong(sc.next());
        Arrays.sort(vert);
        Arrays.sort(hori);
        long hi = hori[n-1]*vert[n-1];
        long lo = hori[0]*vert[0]-1;
        long mid;
        while(hi-lo>1){
            mid = (hi+lo)/2;
            if(check(vert,hori,mid)) hi = mid;
            else lo = mid;
        }
        System.out.println(hi);
    }
    static boolean check(long[] vert, long[] hori, long guess){
        int cnt = 0;
        for(int x=0;x<n;x++){
            long target = guess/hori[x];
            int cur = binary(vert,target);
            cnt += cur;
            if(cnt>=k) return true;
        }
        return cnt>=k;
    }
    // binary finds how many item in a are less than or equal to target
    static int binary(long[] a, long target){
        if(target<a[0]) return 0;
        if(target>=a[n-1]) return n;
        int hi = n-1;
        int lo = -1;
        int mid;
        while(hi-lo>1){
            mid = (hi+lo)/2;
            if(a[mid]<=target) lo=mid;
            else hi = mid;
        }
        return hi;
    }
}