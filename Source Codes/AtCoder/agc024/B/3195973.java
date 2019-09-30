import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] pos = new int[n];
        for (int i = 0; i < n; ++i) {
            pos[sc.nextInt() - 1] = i;
        }

        int max = 1;
        int first = 0;
        for (int i = 1; i < pos.length; ++i) {
            if (pos[i] > pos[i - 1]) {
                max = Math.max(max, i - first + 1);
            } else {
                first = i;
            }
        }

        System.out.println(n - max);
    }
}