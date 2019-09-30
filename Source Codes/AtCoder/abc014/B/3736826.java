import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] line = scanner.nextLine().split(" ", 2);
        int n = Integer.parseInt(line[0]);
        int x = Integer.parseInt(line[1]);

        int result = 0;
        line = scanner.nextLine().split(" ", n);
        for (int i = 0; i < n; i++) {
            if ((x & (1 << i)) != 0) {
                result += Integer.parseInt(line[i]);
            }
        }
        System.out.println(result);
    }
}