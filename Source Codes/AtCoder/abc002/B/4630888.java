import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String w = sc.next();
        String[] vowels = {"a", "i", "u", "e", "o"};

        for (String vowel : vowels) {
            w = w.replace(vowel, "");
        }

        System.out.println(w);
    }
}