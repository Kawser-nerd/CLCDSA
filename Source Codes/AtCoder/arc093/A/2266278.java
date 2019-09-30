import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        ArrayList<Integer> ai = new ArrayList<>();
        int sum = 0;
        int prev = 0;
        ai.add(0);
        for (int i = 0; i < N; i++) {
            int tmp = sc.nextInt();
            ai.add(tmp);
            sum += Math.abs(tmp - prev);
            prev = tmp;
        }
        sum += Math.abs(prev);
        ai.add(0);

        for (int i = 1; i <= N; i++) {
            int a1 = Math.abs(ai.get(i - 1) - ai.get(i));
            int a2 = Math.abs(ai.get(i) - ai.get(i + 1));
            int a3 = Math.abs(ai.get(i + 1) - ai.get(i - 1));
            System.out.println(sum - (a1 + a2 - a3));
        }
    }
}