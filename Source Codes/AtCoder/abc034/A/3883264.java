import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int y = sc.nextInt();
        if (x < y) {
            System.out.println("Better");
        } else {
            System.out.println("Worse");
        }
    }
}