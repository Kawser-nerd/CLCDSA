import java.util.*;

public class Main {
    static long mod = 1000000000+7;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int[] a = new int[n];
        for(int i=0;i<n;i++) a[i] = Integer.parseInt(sc.next());
        int ans = n-LIS(a);
        System.out.println(ans);
    }
    static int LIS(int[] a){
        int n = a.length;
        int[] max = new int[n+1];
        Arrays.fill(max,Integer.MAX_VALUE/2);
        for(int i=0;i<n;i++){
            int idx = Arrays.binarySearch(max,a[i]);
            if(idx>=0) continue;
            idx = -(idx+1);
            max[idx]=Math.min(a[i],max[idx]);
        }
        for(int i=n;i>=0;i--){
            if(max[i]<Integer.MAX_VALUE/2) return i+1;
        }
        return 1;
    }
}