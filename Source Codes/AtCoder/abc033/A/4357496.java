import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String n = sc.next();
        if (n.charAt(0) == n.charAt(1) && n.charAt(1) == n.charAt(2)
            && n.charAt(2) == n.charAt(3)) {
            System.out.println("SAME");
            return;
        }
        System.out.println("DIFFERENT");
    }
}