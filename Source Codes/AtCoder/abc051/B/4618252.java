import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer tokenizer = new StringTokenizer(input.readLine());
        int k = Integer.parseInt(tokenizer.nextToken());
        int s = Integer.parseInt(tokenizer.nextToken());
        int count = 0;
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= k; j++) {
                if (s >= i+j && s-(i+j) <= k){
                    count++;
                }
                if (s < i+j)
                    break;
            }
            if (s < i)
                break;
        }
        out.write(String.valueOf(count));
        out.write("\n");
        out.close();
    }
}