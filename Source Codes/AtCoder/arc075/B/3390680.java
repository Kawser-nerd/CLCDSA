import java.util.*;

class Main {
    static int[] h;
    static int n,A,B;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        A = sc.nextInt();
        B = sc.nextInt();
        h = new int[n+1];
        int max = 0;
        for(int i=1;i<=n;i++) {
            h[i] = sc.nextInt();
            max = Math.max(max,h[i]);
        }
        int lo = 0;
        int hi = (max-1)/B+1;
        while(hi-lo>1){
            int mid = (hi+lo)/2;
            if(check(mid)) hi = mid;
            else lo = mid;
        }
        System.out.println(hi);
    }
    static boolean check(int target){
        int cnt = 0;
        for(int i=1;i<=n;i++){
            int temp = h[i]-target*B;
            if(temp>0) cnt += (temp-1)/(A-B)+1;
            if(cnt>target) return false;
        }
        return true;
    }
}