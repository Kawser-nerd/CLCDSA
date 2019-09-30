import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {

    int n;
    int[] a;

    void run() {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        a = new int[n];
        int[] r = new int[n], l = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        LinkedList<Integer> stack = new LinkedList<>();
        LinkedList<Integer> cnts = new LinkedList<>();
        stack.add(0);
        int cnt = 1;

        for (int i = 0; i < n; i++) {
            l[i] = 1;
            while (stack.getLast() > a[i]) {
                stack.removeLast();
                l[i] += cnts.removeLast();
            }
            stack.addLast(a[i]);
            cnts.addLast(l[i]);
        }

        stack.clear();
        stack.addLast(0);

        for (int i = n - 1; i >= 0; i--) {
            r[i] = 1;
            while (stack.getLast() > a[i]) {
                stack.removeLast();
                r[i] += cnts.removeLast();
            }
            stack.addLast(a[i]);
            cnts.addLast(r[i]);
        }

//        debug(l);
//        debug(r);

        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += 1L * a[i] * l[i] * r[i];
        }

        System.out.println(ans);

    }

    void debug(Object...os) {
        System.err.println(Arrays.deepToString(os));
    }

    public static void main(String[] args) {
        new Main().run();
    }
}