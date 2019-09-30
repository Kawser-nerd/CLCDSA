import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(input.readLine());

        int w = Integer.parseInt(tokenizer.nextToken());
        int a = Integer.parseInt(tokenizer.nextToken());
        int b = Integer.parseInt(tokenizer.nextToken());

        int min = Math.min(a, b);

        int max = Math.max(a, b);

        if (max - min <= w){
            System.out.println(0);
        }else{
            System.out.println(max - (min + w));
        }
    }


}