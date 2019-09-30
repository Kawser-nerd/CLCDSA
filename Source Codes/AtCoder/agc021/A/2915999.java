import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int k = s.length();
        int c = Character.getNumericValue(s.charAt(0));
        for (int i = 1; i < k; i++) {
            if (s.charAt(i) != '9') {
                System.out.println(c + 9 * (k - 1) - 1);
                return;
            }
        }
        System.out.println(c + 9 * (k - 1));
    }
}