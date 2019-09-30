import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int x = sc.nextInt();
        int goal_0 = 0;
        int goal_n = 0;

        int[] a = new int[m];
        for (int i = 0; i < m; i++) {
            a[i] = sc.nextInt();
            if (a[i] < x) {
                goal_0++;
            }
            if (a[i] > x) {
                goal_n++;
            }
        }
        System.out.println(Math.min(goal_0,goal_n));
    }
}