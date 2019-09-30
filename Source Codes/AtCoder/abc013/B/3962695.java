import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        if (Math.abs(b - a) > 5) {
            System.out.println(10 - Math.abs(b - a));
        } else {
            System.out.println(Math.abs(b - a));
        }
    }
}