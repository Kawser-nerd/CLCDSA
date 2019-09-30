import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String args[]) throws Exception{
        BufferedReader stdR = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(stdR.readLine());
        long pow = 1;
        for(int i = 1 ; i <= N ; i++) {
            pow *= i;
            pow %= 1000000007;
        }
        System.out.println(pow);
    }
}