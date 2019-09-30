import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main{
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());
        int m = 1000000007;
        long sum = 1;

        for (int i = 1; i <= n; i++) {
            sum *= i;
            sum %= m;
        }

        System.out.println(sum);

    }
}