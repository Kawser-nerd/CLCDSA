import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int c = sc.nextInt();
        int k = sc.nextInt();
        int[] t = new int[n];
        for (int i = 0; i < n; i++) {
            t[i] = sc.nextInt();
        }
        Arrays.sort(t);
        int preT = t[0];
        int sum = 0;
        long ans = 0;
        for (int i = 0; i < n; i++) {
            if(t[i] - preT > k){
                ans++;
                sum -= Math.min(sum, c);
                preT = t[i];
            }
            sum++;
            if(sum >= c){
                ans++;
                sum -= Math.min(sum, c);
                if(i < n-1) preT = t[i+1];
            }

        }
        if(sum > 0) ans++;
        System.out.println(ans);
        sc.close();
    }

}