import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(),K=sc.nextInt();
        long[] sum = new long[n+1], a = new long[n+1], posi = new long[n+1];
        for(int i=1;i<=n;i++){
            a[i] = sc.nextLong();
            sum[i] = sum[i-1]+a[i];
            posi[i] = posi[i-1]+Math.max(0,a[i]);
        }
        long ans = 0;
        for(int start =1; start+K-1<=n;start++){
            int end = start+K-1;
            long cur = Math.max(0,sum[end]-sum[start-1]);
            cur += posi[start-1]+posi[n]-posi[end];
            ans = Math.max(ans,cur);
        }
        System.out.println(ans);
    }
}