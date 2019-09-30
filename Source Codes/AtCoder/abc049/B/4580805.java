import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(input.readLine());
        int x = Integer.parseInt(tokenizer.nextToken());
        int y = Integer.parseInt(tokenizer.nextToken());
        char [][] image = new char[x][];

        for (int i = 0; i < x; i++) {
            image[i] = input.readLine().toCharArray();
        }
        StringBuilder out = new StringBuilder();
        for (int i = 0; i < x * 2; i++) {
            for (int j = 0; j < y; j++) {
                out.append(image[(i/2)][j]);
            }
            System.out.println(out);
            out = new StringBuilder();
        }
    }
}