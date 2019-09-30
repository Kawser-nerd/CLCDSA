import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());
        StringTokenizer tokenizer = new StringTokenizer(input.readLine());
        int [] values = new int[n];
        for (int i = 0; i < n; i++) {
            values[i] = Integer.parseInt(tokenizer.nextToken());
        }
        Arrays.sort(values);

        boolean state = true;
        int sum1 =0, sum2 = 0;

        for (int i = n - 1; i > -1; i--) {
            if (state){
                sum1 += values[i];
                state = false;
            }else {
                sum2  += values[i];
                state = true;
            }
        }

        System.out.println(Math.abs(sum1 - sum2));
    }
}