import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main{
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        input.readLine();
        String word = input.readLine();
        int value = 0;
        int max = 0;
        for (int i = 0; i < word.length(); i++) {
            if (word.charAt(i) == 'I'){
                value++;
            }else{
                value--;
            }
            max = Math.max(max, value);
        }
        System.out.println(max);
    }
}