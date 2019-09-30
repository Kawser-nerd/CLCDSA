import java.util.Scanner;

public class Main {

    private static boolean containsC(String s) {
        String[] str = s.split("");
        int cCount = 0;
        for (int i = 2; i < str.length - 1; i++) {
            if ("C".equals(str[i])) {
                cCount++;
            }
        }
        return cCount == 1;
    }

    private static boolean isLowerCaseWoAAndC(String s) {
        String[] str = s.split("");
        for (int i = 1; i < str.length; i++) {
            if ("C".equals(str[i])) {
                continue;
            }
            if (str[i].equals(str[i].toUpperCase())) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        if ("A".equals(s.substring(0, 1))
                && containsC(s)
                && isLowerCaseWoAAndC(s)) {
            System.out.println("AC");
            return;
        }
        System.out.println("WA");
    }

}