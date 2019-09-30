import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        String word1 = input.readLine();
        String word2 = input.readLine();
        boolean state = true;
        for (int i = 0, j = word2.length() - 1; i < word1.length(); i++, j--) {
            if (word1.charAt(i) != word2.charAt(j)){
                state = false;
                break;
            }
        }
        if (state)
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}