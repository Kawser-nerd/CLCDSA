import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        String word = input.readLine();
        boolean [] freq = new boolean[26];
        for (char c: word.toCharArray()) {
            freq[c - 'a'] = true;
        }

        for (int i = 0; i < 26; i++) {
            if (!freq[i]){
                System.out.println((char)(i + 'a'));
                return;
            }
        }
        System.out.println("None");
    }
}