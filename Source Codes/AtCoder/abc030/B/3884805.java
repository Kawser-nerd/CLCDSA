import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        if (n >= 12) {
            n = n - 12;
        }

        double argN = (double) n * 30 + m * 0.5;
        double argM = (double) m * 6;

        double arg = Math.abs(argN - argM);
        if (arg > 180.0) {
            arg = 360.0 - arg;
        }

        System.out.println(arg);
    }
}