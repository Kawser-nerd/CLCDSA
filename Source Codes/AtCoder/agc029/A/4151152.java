import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        sc.close();

        String[] str = s.split("");

        Arrays.sort(str, Comparator.reverseOrder());

        long ans = 0;

        for (int i = 0; i < s.length(); i++) {
            if (str[i].equals("B")) {
                ans += i;
            }
        }

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'B') {
                ans -= i;
            }
        }

        System.out.println(ans);
    }
}