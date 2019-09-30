import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main{
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(input.readLine());
        int m = 1000000007;
        long sum = 1;

        for (int i = 1; i <= n; i++) {
            sum *= i;
            sum %= m;
        }

        out.write(String.valueOf(sum));
        out.write("\n");
        out.close();
        

    }
}