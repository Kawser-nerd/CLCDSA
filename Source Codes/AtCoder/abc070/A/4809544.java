import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());

        System.out.println(n == getRevers(n) ? "Yes" : "No");
    }

    public static int getRevers(int n){
        int reverse = 0;
        while (n > 9){
            reverse = reverse * 10 + (n %10);
            n /= 10;
        }
        if (n > 0)
            reverse = reverse  * 10 + n;

        return reverse;
    }
}