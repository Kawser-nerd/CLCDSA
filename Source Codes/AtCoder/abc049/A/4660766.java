import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main{
    public static void main(String[] args)throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

        String a = input.readLine();

        System.out.println("aeiou".contains(a) ? "vowel" : "consonant");
    }
}