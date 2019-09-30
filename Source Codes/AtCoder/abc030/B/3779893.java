import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] line = scanner.nextLine().split(" ", 2);
        int n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);

        double n60 = ((double)(n % 12) + ((double)m / 60.0)) * 5.0;
        double diff = Math.abs(n60 - (double)m);
        if (diff > 30.0) {
            diff = 60.0 - diff;
        }

        System.out.println(6.0 * diff);
    }
}