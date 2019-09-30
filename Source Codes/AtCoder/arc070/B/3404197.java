import java.util.*;

class Main {
    static int n;
    static int k;
    static int[] a;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        a = new int[n];
        for(int i=0;i<n;i++) a[i] = sc.nextInt();
        Arrays.sort(a);
        if(check(0)){
            System.out.println(0);
            System.exit(0);
        }
        if(!check(n-1)){
            System.out.println(n);
            System.exit(0);
        }
        int hi = n-1;
        int lo = 0;
        while(hi-lo>1){
            int mid = (lo+hi)/2;
            if(check(mid)) hi = mid;
            else lo = mid;
        }
        System.out.println(hi);
    }
    static boolean check(int idx){
        int cur = a[idx];
        boolean[] range = new boolean[k+1];
        range[0]=true;
        for(int i=0;i<n;i++){
            if(i==idx) continue;
            int now = a[i];
            for(int j=k;j>=now;j--){
                if(range[j-now]) {
                    range[j] = true;
                    if(k-cur<=j&&j<k) return true;
                }
            }
        }
        for(int j=Math.max(0,k-cur);j<k;j++){
            if(range[j]) return true;
        }
        return false;
    }
}