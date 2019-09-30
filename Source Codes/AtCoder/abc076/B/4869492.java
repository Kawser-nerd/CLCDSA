import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());
        int k = Integer.parseInt(input.readLine());
        System.out.println(calc(n, 1, k, 1));
    }

    public static int  calc (int k, int count, int incrementValue  ,int sum){
        if (count > k){
            return sum;
        }

        return Math.min(calc(k, count + 1, incrementValue,sum * 2), calc(k, count + 1, incrementValue , sum + incrementValue));
    }
}