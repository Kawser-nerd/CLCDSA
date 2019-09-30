import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i=0;i<n;i++) a[i]=sc.nextInt();
        Arrays.sort(a);
        System.out.print(Integer.toString(a[n-1])+" ");
        int ans = a[n-2];
        if(a[n-1]%2==0){
            int target = a[n-1]/2;
            for(int i=n-3;i>=0;i--){
                if(Math.abs(target-a[i])<Math.abs(target-ans)) ans = a[i];
            }
        }
        else{
            int t1 = a[n-1]/2;
            int t2 = a[n-1]/2+1;
            for(int i=n-3;i>=0;i--){
                int old = Math.min(Math.abs(ans-t1),Math.abs(ans-t2));
                int cur = Math.min(Math.abs(a[i]-t1),Math.abs(a[i]-t2));
                if(cur<old) ans = a[i];
            }
        }
        System.out.print(ans);
    }
}