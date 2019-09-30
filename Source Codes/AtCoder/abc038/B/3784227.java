import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] hw1 = scanner.nextLine().split(" ", 2);
        String[] hw2 = scanner.nextLine().split(" ", 2);
        int h1 = Integer.parseInt(hw1[0]);
        int w1 = Integer.parseInt(hw1[1]);
        int h2 = Integer.parseInt(hw2[0]);
        int w2 = Integer.parseInt(hw2[1]);

        if (h1 == h2 || h1 == w2 || w1 == h2 || w1 == w2) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}