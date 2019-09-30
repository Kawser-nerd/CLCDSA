import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int x = sc.nextInt();
        int donut = n;
        int min = 1000;
        int add = 0;

        int[] m = new int[n];
        for (int i = 0; i < n; i++) {
            m[i] = sc.nextInt();
            add += m[i];
            if (min > m[i]) {
                min = m[i];
            }
        }
        donut += (x - add) / min;

        System.out.println(donut);
    }
}