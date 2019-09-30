import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int hour = n / 3600;
        int min = (n % 3600) / 60;
        int sec = n % 60;
        System.out.printf("%02d:%02d:%02d\n", hour, min, sec);
    }
}