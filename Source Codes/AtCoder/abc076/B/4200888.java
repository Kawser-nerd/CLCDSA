import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();

        int num = 1;
        for (int i = 0; i < n; i++) {
            if (num * 2 < num + k) {
                num *= 2;
                continue;
            }
            num += k;
        }
        System.out.println(num);
    }

}