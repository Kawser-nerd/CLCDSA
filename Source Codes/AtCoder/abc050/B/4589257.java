import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());
        int [] problems = new int[n];
        int sum = 0;
        StringTokenizer tokenizer = new StringTokenizer(input.readLine());
        for (int i = 0; i < n; i++) {
            problems[i] = Integer.parseInt(tokenizer.nextToken());
            sum += problems[i];
        }
        StringBuilder out = new StringBuilder();
        int m = Integer.parseInt(input.readLine());
        for (int i = 0; i < m; i++) {
            tokenizer = new StringTokenizer(input.readLine());
            out.append((sum - problems[Integer.parseInt(tokenizer.nextToken()) - 1]) + Integer.parseInt(tokenizer.nextToken())).append("\n");
        }
        System.out.print(out);
    }
}