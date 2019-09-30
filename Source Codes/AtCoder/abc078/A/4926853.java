import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            String a = sc.next();
            String b = sc.next();
            char ach = a.charAt(0);
            char bch = b.charAt(0);
            if ( ach > bch ) {
                System.out.println(">");
            } else if ( ach < bch ) {
                System.out.println("<");
            } else {
                System.out.println("=");
            }
        }
    }
}