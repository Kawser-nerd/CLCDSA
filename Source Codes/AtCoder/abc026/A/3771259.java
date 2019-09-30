import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        int a = new Scanner(System.in).nextInt();
        int max = 0;
        for (int i = 1; i < a; i++) {
            int n = i * (a - i);
            if (n > max) {
                max = n;
            }
        }
        System.out.println(max);
    }
}