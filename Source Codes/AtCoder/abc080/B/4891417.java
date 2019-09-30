import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());

        System.out.println(n % getSum(n) == 0 ? "Yes" : "No");

    }

    public static int  getSum(int n){
        int sum = 0;
        while (n > 9){
            sum += n % 10;
            n /= 10;
        }

        if (n > 0)
            sum +=n;

        return sum;
    }
}