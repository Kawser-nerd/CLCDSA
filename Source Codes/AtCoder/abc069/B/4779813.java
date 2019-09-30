import java.io.BufferedReader;
    import java.io.InputStreamReader;

    public class Main {
        public static void main(String[] args)throws Exception {
            BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
            String word = input.readLine();
            System.out.println(word.charAt(0) + String.valueOf(word.length() - 2) + word.charAt(word.length() - 1));
        }
    }