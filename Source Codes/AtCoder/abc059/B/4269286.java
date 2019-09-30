import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String a = sc.next();
        String b = sc.next();
        
        String s = "EQUAL";

        if (a.length() > b.length()) {
            System.out.println("GREATER");
            System.exit(0);
        }
        if (a.length() < b.length()) {
            System.out.println("LESS");
            System.exit(0);
        }


        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) > b.charAt(i)) {
                s = "GREATER";
                break;
            }
            if (a.charAt(i) < b.charAt(i)) {
                s = "LESS";
                break;
            }
        }

        System.out.println(s);
        System.exit(0);
    }
}