import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        int[] c = new int[n];
        for(int i=0; i<n; i++){
            a[i] = sc.nextInt();
        }
        for(int i=0; i<n; i++){
            b[i] = sc.nextInt();
        }
        for(int i=0; i<n; i++){
            c[i] = sc.nextInt();
        }
        sc.close();

        Arrays.sort(a);
        Arrays.sort(b);
        Arrays.sort(c);

        long ans = 0;
        long[] cnum = new long[n+1];
        int pos = 0;
        for(int i=0; i<n; i++){
            while(c[pos] <= b[i]){
                pos++;
                if(pos >= n){
                    pos = n;
                    break;
                }
            }
            if(pos >= n) break;
            cnum[i] = n - pos;
        }
        for(int i=1; i<n; i++){
            cnum[n-i-1] = cnum[n-i] + cnum[n-i-1];
        }
        pos = 0;
        for(int i=0; i<n; i++){
            while(b[pos] <= a[i]){
                pos++;
                if(pos >= n){
                    pos = n;
                    break;
                }
            }
            if(pos >= n) break;
            ans += cnum[pos];
        }

        System.out.println(ans);
    }
}