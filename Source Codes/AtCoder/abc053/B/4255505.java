import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.next();

        int min = 0;
        int max = 0;

        for (int i = 0; i < s.length(); i++) {
            if (min == 0 && s.charAt(i) == 'A')
                min = i+1;
            if (min > 0 && s.charAt(i) == 'Z')
                max = i+1;
        }

        int ans = max - min;
        System.out.println(ans+1);
    }
}