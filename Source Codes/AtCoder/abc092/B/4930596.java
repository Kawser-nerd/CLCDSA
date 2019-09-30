import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());
        StringTokenizer tokenizer = new StringTokenizer(input.readLine());
        int d = Integer.parseInt(tokenizer.nextToken());
        int x = Integer.parseInt(tokenizer.nextToken());
        int sum, count, index;

        for (int i = 0; i < n; i++) {
            sum = 0;
            count = 0;
            index = 1;
            int value = Integer.parseInt(input.readLine());
            while (count <= d){
                sum++;
                count  = (index * value) + 1;
                index++;
            }
            x+= sum;
        }
        System.out.println(x);
    }
}