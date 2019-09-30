import java.util.*;

public class Main {

    public void run() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> arr = new ArrayList<>();

        int max = Integer.MIN_VALUE, maxId = -1;
        int min = Integer.MAX_VALUE, minId = -1;
        for (int i = 0; i < n; i++) {
            int m = sc.nextInt();
            arr.add(m);

            if (m > max) {
                max = m;
                maxId = i;
            }
            if (m < min) {
                min = m;
                minId = i;
            }
        }

        int id = Math.abs(max) - Math.abs(min) > 0 ? maxId : minId;

        System.out.println(2 * n - 2);

        for (int i = 0; i < n; i++) {
            if (i != id) {
                System.out.println(String.format("%d %d", id + 1, i + 1));
            }
        }

        if(Math.abs(max) - Math.abs(min) > 0) {
            for (int i = 0; i < n - 1; i++) {
                System.out.println(String.format("%d %d", i + 1, i + 2));
            }
        } else {
            for (int i = n - 1; i > 0; i--) {
                System.out.println(String.format("%d %d", i + 1, i));
            }

        }
    }

    public static void main(String[] args) {
        new Main().run();
    }
}