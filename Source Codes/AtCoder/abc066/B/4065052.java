import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        for (int i = 1; i < s.length(); ++i) {
            if (check(s.substring(0, s.length()-i))) {
                System.out.println(s.length()-i);
                return;
            }
        }
    }

    public static boolean check(String s) {
        if (s.length() % 2 != 0) {
            return false;
        }

        for (int i = 0; i < s.length() / 2; ++i) {
            if (s.charAt(i) != s.charAt(i+s.length()/2)) {
                return false;
            }
        }

        return true;
    }
}