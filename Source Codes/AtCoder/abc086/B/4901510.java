import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(input.readLine());
        int number = Integer.parseInt(tokenizer.nextToken() + tokenizer.nextToken());
        double result = Math.sqrt(number);
        int round = (int) result;
        System.out.println(result == round ? "Yes" : "No");
    }
}