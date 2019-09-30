import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Created by jaga on 9/6/16.
 * dp???????
 * ?????? -A???????????0????????????
 * dp[j][k] = j??(0-indexed)??????????k???????  j < N , - N*50 < k < N*50 + 1
 * k??? k + N*50??????(?????????)
 * dp[j][k] = dp[j - 1][k] + dp[j-1][k - x[j]]
 * j-1??????????j??????? + j - 1???????k-x[j]?????j???
 * ???+??x[j]?k????dp[j-1][k] = 0??1????????????????
 */
public class Main {
    public static void main (String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        String text[] = line.split(" ");

        int N,A;
        N = Integer.parseInt(text[0]);
        A = Integer.parseInt(text[1]);

        line = br.readLine();
        text = line.split(" ");

        int [] x = new int[N];

        for(int i = 0; i < N ; i++){
            x[i]  = Integer.parseInt(text[i]) - A;
//            System.out.println(x[i]);
        }

        long dp[][] = new long [N][N * 50 * 2 + 1];
        int dpl = 50 * N;

        dp[0][x[0] + dpl] = 1;

        for(int j = 1; j < N; j++){

            for(int k  = -1 * N * 50; k < N * 50 + 1; k++){
//                System.out.println(k + dpl - x[j]);
                if(k + dpl - x[j] >= 0 && k + dpl - x[j] <= 50*N*2){
//                if(k + dpl - x[j] >= 0 ){
                    dp[j][k + dpl] = dp[j-1][k + dpl] + dp[j-1][k + dpl - x[j]];
                }else {
                    dp[j][k + dpl] = dp[j - 1][k + dpl];
                }
                if(x[j] == k) dp[j][k + dpl] ++;

//                System.out.println("dp[" + j + "][" + k + "] = " + dp[j][k + dpl]);
            }
        }


        System.out.println(dp[N - 1 ][dpl]);
    }
}