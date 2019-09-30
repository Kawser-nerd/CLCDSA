import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int Q = sc.nextInt();
        char arr[] = sc.next().toCharArray();
        int dp[] = new int[arr.length];
        for(int i = 1 ; i < dp.length ; i++){
            if(arr[i]=='C' && arr[i-1] == 'A'){
                dp[i] = 1;
            }
        }
        for(int i = 1; i < dp.length;i++){
            dp[i] += dp[i-1];
        }
        while(Q-->0){
            int l = sc.nextInt();
            int r = sc.nextInt();
            l--;
            r--;
            int val = dp[r] - dp[l];
            System.out.println(val);
        }
    }
}