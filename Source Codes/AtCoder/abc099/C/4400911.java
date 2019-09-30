import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int dp[] = new int[n+1];
        Arrays.fill(dp,Integer.MAX_VALUE-1);
        dp[0] = 0;
        HashSet<Integer> set = new HashSet<>();
        set.add(1);
        int num = 1;
        while(num <= n){
            num *= 6;
            set.add(num);
        }
        num = 1;
        while(num <= n){
            num *= 9;
            set.add(num);
        }

        for(Integer val : set){
            for(int i = val; i < dp.length ; i++){
                dp[i] = Math.min(dp[i],1+dp[i-val]);
            }
        }
        System.out.println(dp[n]);
    }
}