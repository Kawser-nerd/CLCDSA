import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());

        int start = 1;
        while (start * 2 <= n){
                start *= 2;
        }

        System.out.println(start);
    }
}