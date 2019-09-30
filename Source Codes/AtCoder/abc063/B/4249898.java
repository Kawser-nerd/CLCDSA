import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        char[] c = s.toCharArray();

        Arrays.sort(c);

        boolean isAns = true;
        for (int i = 1; i < c.length; i++) {
            if (c[i] == c[i-1]) {
                isAns = false;
                break;
            }
        }

        System.out.println(isAns ? "yes" : "no");
    }
}