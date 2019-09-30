import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(input.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        int k = Integer.parseInt(tokenizer.nextToken());
        BigInteger bigDecimal = BigInteger.valueOf(k);
        for (int i = 1; i < n; i++) {
            bigDecimal = bigDecimal.multiply(BigInteger.valueOf(k - 1));
        }
        System.out.println(bigDecimal);
    }
}