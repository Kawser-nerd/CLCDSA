import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] line = scanner.nextLine().split(" ", 2);
        int n = Integer.parseInt(line[0]);
        int t = Integer.parseInt(line[1]);

        int total = 0;
        int lastOpen = 0;
        for (int i = 0; i < n; i++) {
            int a = Integer.parseInt(scanner.nextLine());
            total += Math.max((a + t) - Math.max(lastOpen, a), 0);
            lastOpen = Math.max(a + t, lastOpen);
        }
        System.out.println(total);
    }
}