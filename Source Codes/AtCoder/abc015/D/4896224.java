import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int w = Integer.parseInt(br.readLine());
        String[] tmp = br.readLine().split(" ");
        int n = Integer.parseInt(tmp[0]);
        int k = Integer.parseInt(tmp[1]);
        int[] a = new int[n];
        int[] b = new int[n];
        for(int i = 0; i < n; i++) {
            tmp = br.readLine().split(" ");
            a[i] = Integer.parseInt(tmp[0]);
            b[i] = Integer.parseInt(tmp[1]);
        }

        int[][][] dp = new int[n + 1][w + 1][k + 1];
        for(int index = 0; index < n; index++) {
            for(int width = 0; width <= w; width++) {
                for(int num = 0; num < k; num++) {
                    if(a[index] > width) dp[index + 1][width][num + 1] = dp[index][width][num + 1];
                    else dp[index + 1][width][num +1] = Math.max(dp[index][width][num + 1], dp[index][width - a[index]][num] + b[index]);
                }
            }
        }

        System.out.println(dp[n][w][k]);
    }
}