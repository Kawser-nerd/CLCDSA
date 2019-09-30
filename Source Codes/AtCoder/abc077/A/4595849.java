import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String c1 = sc.next();
        String c2 = sc.next();

        if (c1.charAt(0) == c2.charAt(2) && c1.charAt(1) == c2.charAt(1) && c1.charAt(2) == c2.charAt(0)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}