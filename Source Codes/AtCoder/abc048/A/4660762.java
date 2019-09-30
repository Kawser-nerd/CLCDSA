import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer tokenizer = new StringTokenizer(input.readLine());

        StringBuilder output = new StringBuilder();

        while (tokenizer.hasMoreTokens())
            output.append(tokenizer.nextToken().charAt(0));

        System.out.println(output);
    }
}