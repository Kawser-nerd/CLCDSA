import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        int n = Integer.parseInt(scanner.nextLine());

        for (int i = 0; i < n; i++) {
            String[] line = scanner.nextLine().split(" ", 2);
            int left = Integer.parseInt(line[0]) - 1;
            int right = Integer.parseInt(line[1]) - 1;

            s = String.format("%s%s%s",
                    s.substring(0, left),
                    new StringBuilder(s.substring(left, right + 1)).reverse().toString(),
                    s.substring(right + 1, s.length()));
        }
        System.out.println(s);
    }
}