import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(input.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        int m = Integer.parseInt(tokenizer.nextToken());
        tokenizer = new StringTokenizer(input.readLine());
        int [] values = new int[n];
        for (int i = 0; i < n; i++) {
            values[i] = Integer.parseInt(tokenizer.nextToken());
        }
        Arrays. sort(values);
        long sum = 0;
        for (int i = n - 1; i >= n - m; i--) {
            sum += values[i];
        }
        System.out.println(sum);
    }
}