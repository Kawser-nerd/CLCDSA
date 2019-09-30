import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int x = sc.nextInt();
        int[] points = new int[m];

        int left = 0;
        int right = 0;

        for (int point : points) {
            point = sc.nextInt();
            if (point < x) {
                left++;
            } else {
                right++;
            }
        }
        System.out.println(Math.min(left, right));
    }
}