import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        int n, a, b, digitsSum = 0, totalSum = 0;

        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        a = sc.nextInt();
        b = sc.nextInt();

        for (int i = 1; i <= n; i++) {
            int tmp = i;
            for (int j = 0; j < 5; j++){
                digitsSum += tmp % 10;
                tmp /= 10;
            }
            if(a <= digitsSum && digitsSum <= b) totalSum += i;
            digitsSum = 0;
        }
        System.out.println(totalSum);
    }

}