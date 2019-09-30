import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(input.readLine());
        int k = Integer.parseInt(tokenizer.nextToken());
        int s = Integer.parseInt(tokenizer.nextToken());
        int count = 0;
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= k; j++) {
                if (s >= i+j && s-(i+j) <= k){
                    count++;
                }
            }
        }
        System.out.println(count);

    }
}