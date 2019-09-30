import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            String arare = sc.next();
            if (arare.equals("Y")){
                System.out.println("Four");
                System.exit(0);
            }
        }
        System.out.println("Three");
    }
}