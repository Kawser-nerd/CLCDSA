import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        String word = input.readLine();
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < word.length(); i+=2) {
            builder.append(word.charAt(i));
        }
        System.out.println(builder);
    }
}