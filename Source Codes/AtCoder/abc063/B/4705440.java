import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main{
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        String word = input.readLine();
        boolean [] state  = new boolean[26];

        for (int i = 0; i < word.length(); i++) {
            if (state[word.charAt(i) - 'a']){
                System.out.println("no");
                return;
            }
            state[word.charAt(i) - 'a'] = true;
        }
        System.out.println("yes");
    }
}