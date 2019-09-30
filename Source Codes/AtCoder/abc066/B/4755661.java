import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main{
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        String word = input.readLine();
        int largest = 0;
        for (int i = word.length() - 1; i > 1; i--) {
            if (i % 2 == 0) {
                int midle = i / 2;
                boolean state = true;
                for (int j = 0; j < i / 2; j++, midle++) {
                    if (word.charAt(j) != word.charAt(midle)){
                        state = false;
                        break;
                    }
                }
                if (state)
                    largest = Math.max(largest, i);
            }
        }
        System.out.println(largest);
    }
}