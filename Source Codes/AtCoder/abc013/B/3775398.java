import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = Integer.parseInt(scanner.nextLine());
        int b = Integer.parseInt(scanner.nextLine());
        int c;
        if (a < b) {
            c = b - 10;
        } else {
            c = b + 10;
        }
        System.out.println(Math.min(Math.abs(b - a), Math.abs(c - a)));
    }
}