import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[n];
        for(int i=0; i<n; i++) a[i] = sc.nextLong();
        sc.close();

        long ans = 0;
        for(int i=0; i<n; i++){
            long min = Math.max(n, Arrays.stream(a).min().getAsLong());
            // min += Math.max(0, (a[i]-min)/n);
            // if(i==0) min = n;
            // long rem = Math.max(0, a[i] - min);
            // long div = rem / n;
            long div = (a[i] - min) / (n+1);
            ans += div;
            a[i] -= div * n;
            for(int j=0; j<n; j++){
                if(i==j) continue;
                a[j] += div;
            }
        }
        
        long min = Arrays.stream(a).min().getAsLong();
        if(min >= n){
            ans += (min - n + 1) * n;
            for(int i=0; i<n; i++){
                a[i] -= (min - n + 1);
            }
        }

        while(true){
            int maxpos = 0;
            long max = Long.MIN_VALUE;
            for(int i=0; i<n; i++){
                if(a[i] > max){
                    max = a[i];
                    maxpos = i;
                }
            }
            if(max < n) break;
            ans++;
            a[maxpos] -= n;
            for(int i=0; i<n; i++){
                if(i == maxpos) continue;
                a[i]++;
            }
        }

        System.out.println(ans);
    }
}