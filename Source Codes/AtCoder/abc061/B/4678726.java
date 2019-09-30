import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(input.readLine());
        int a = Integer.parseInt(tokenizer.nextToken());
        int b = Integer.parseInt(tokenizer.nextToken());
        int [] city = new int[a + 1];

        for (int i = 0; i < b; i++) {
            tokenizer = new StringTokenizer(input.readLine());
            city[Integer.parseInt(tokenizer.nextToken())]++;
            city[Integer.parseInt(tokenizer.nextToken())]++;
        }
        StringBuilder output = new StringBuilder();
        for (int i = 1; i <= a; i++) {
            output.append(city[i]).append("\n");
        }
        System.out.print(output);
    }
}