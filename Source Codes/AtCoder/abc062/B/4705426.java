import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(input.readLine());
        int x = Integer.parseInt(tokenizer.nextToken());
        int y = Integer.parseInt(tokenizer.nextToken());
        StringBuilder firstAndLast = new StringBuilder();
        for (int i = 0; i < y + 2; i++) {
            firstAndLast.append('#');
        }
        StringBuilder out = new StringBuilder();
        out.append(firstAndLast).append('\n');
        for (int i = 0; i < x; i++) {
            out.append('#').append(input.readLine()).append('#').append('\n');
        }
        out.append(firstAndLast).append('\n');
        System.out.print(out);
    }
}