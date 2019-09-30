import java.util.*;

class Main {
    static long[] bit0,bit1;
    static int[] a;
    static int m,n;
    static int maxN = 100000+100;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        a = new int[n+1];
        bit0 = new long[100000+100];
        bit1 = new long[100000+100];
        for(int i=1;i<=n;i++) a[i]=sc.nextInt();
        long oriSum = 0;
        for(int i=1;i<n;i++) oriSum += a[i]<a[i+1]?a[i+1]-a[i]:m-a[i]+a[i+1];
        long temp[] = new long[m+1];
        for(int i=1;i<=n-1;i++) {
            handle(a[i],a[i+1]);
        }
        long res = 0;
        for(int j=1;j<=m;j++) temp[j] = sim_sum(j);
        for(int i=1;i<=m;i++) res = Math.max(res,temp[i]);
        System.out.println(oriSum-res);
    }

    static long sum(long[] bit, int i){
        long ans = 0;
        while(i>0){
            ans += bit[i];
            i -= i&(-i);
        }
        return ans;
    }

    static void add(long[] bit, int idx, long val){
        while(idx<=m){
            bit[idx] += val;
            idx += idx&(-idx);
        }
    }

    static long sim_sum(int i){
        return sum(bit1,i)*i+sum(bit0,i);
    }
    // here simulate adding val to all position within the interval [left,right]
    static void sim_add(int left, int right, long val){
        if(left>right){
            return;
        }
        add(bit0,left,-val*(left-1));
        add(bit1,left,val);
        add(bit0,right+1,val*right);
        add(bit1,right+1,-val);
    }

    static void handle(int from, int to){
        if(from<to){
            if(from==to-1) return;
            sim_add(from+2,to,1);
            sim_add(to+1,to+1,-(to-from-1));
        } else if(from > to){
            sim_add(from+2,m,1);
            sim_add(1,1,m-from);
            sim_add(2,to,1);
            sim_add(to+1,to+1,-(m-from+to-1));
        }
    }
}