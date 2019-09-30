import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args)throws  Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(input.readLine());
        int a = Integer.parseInt(tokenizer.nextToken());
        int b = Integer.parseInt(tokenizer.nextToken());
        int count = 0;
        for (int i = a; i <= b; i++) {
            if (isBlandrome(i))
                count++;
        }
        System.out.println(count);
    }

    public static boolean isBlandrome(int n){
        int copy = n;

        int newN = 0;

        while (n > 9){
            newN = newN * 10 + (n % 10);
            n /= 10;
        }

        if (n > 0){
            newN = newN * 10 + (n % 10);
        }

        return  newN == copy;
    }
}