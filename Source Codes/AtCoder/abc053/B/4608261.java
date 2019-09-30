import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main{
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        String word = input.readLine();
        int start = -1, end = -1;
        for (int i = 0; i < word.length(); i++) {
            if (word.charAt(i) == 'A'){
                start = i;
                break;
            }
        }

        for (int i = word.length() - 1; i > 0; i--) {
            if (word.charAt(i) == 'Z'){
                end = i;
                break;
            }
        }

        System.out.println(end - start + 1);
    }
}