import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(input.readLine());
        int a = Integer.parseInt(tokenizer.nextToken());
        int b = Integer.parseInt(tokenizer.nextToken());
        String word = input.readLine();
        int size = 0;
        boolean correct = true;
        boolean foundMinuse = false;
        for (int i = 0; i < word.length(); i++) {
            if (Character.isDigit(word.charAt(i))){
                size++;
            }else{
                if (size != a){
                    correct = false;
                    break;
                }
                size = 0;
                foundMinuse = true;
            }
        }

        if (foundMinuse && size == b){
            System.out.println("Yes");
        }else {
            System.out.println("No");
        }
    }
}