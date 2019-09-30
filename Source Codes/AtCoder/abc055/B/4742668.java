import java.util.Scanner;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        sc.close();
        long power = 1;
        long c = (long) (Math.pow(10, 9) + 7);

        for (int i = 1; i <= N; i++) {
            power *= i;
            power %= c;
        }
        System.out.println(power);
    }
}