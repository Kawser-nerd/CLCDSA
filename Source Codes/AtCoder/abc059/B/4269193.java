import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String a = sc.next();
        String b = sc.next();

        if (a.length() != b.length()) {
            if (a.length() > b.length())
                System.out.println("GREATER");
            else
                System.out.println("LESS");
            System.exit(0);
        }

        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) {
                if (a.charAt(i) > b.charAt(i))
                    System.out.println("GREATER");
                else
                    System.out.println("LESS");
                System.exit(0);
            }
        }

        System.out.println("EQUAL");
        System.exit(0);
    }
}