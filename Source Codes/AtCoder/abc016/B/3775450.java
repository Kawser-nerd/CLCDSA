import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] line = scanner.nextLine().split(" ", 3);
        int a = Integer.parseInt(line[0]);
        int b = Integer.parseInt(line[1]);
        int c = Integer.parseInt(line[2]);

        if (a + b == c && a - b != c) {
            System.out.println("+");
        } else if (a + b != c && a - b == c) {
            System.out.println("-");
        } else if (a + b == c && a - b == c) {
            System.out.println("?");
        } else {
            System.out.println("!");
        }
    }
}