import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] line = scanner.nextLine().split(" ", 2);
        int l = Integer.parseInt(line[0]);
        int h = Integer.parseInt(line[1]);
        int n = Integer.parseInt(scanner.nextLine());

        for (int i = 0; i < n; i++) {
            int a = Integer.parseInt(scanner.nextLine());
            if (h < a) {
                System.out.println(-1);
            } else if (a < l) {
                System.out.println(l - a);
            } else {
                System.out.println(0);
            }
        }
    }
}