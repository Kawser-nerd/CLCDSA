import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String a = sc.next();
        String b = sc.next();
        String c = sc.next();

        if (a.substring(a.length()-1).equals(b.substring(0, 1)) && (b.substring(b.length()-1).equals(c.substring(0, 1)))) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}