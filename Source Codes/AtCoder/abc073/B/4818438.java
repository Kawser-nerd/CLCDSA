import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
         int n = Integer.parseInt(input.readLine());
        StringTokenizer tokenizer;
        long sum = 0;
        for (int i = 0; i < n; i++) {
            tokenizer = new StringTokenizer(input.readLine());
            sum += Math.abs(Integer.parseInt(tokenizer.nextToken()) - Integer.parseInt(tokenizer.nextToken())) + 1;
        }
        System.out.println(sum);
    }
}