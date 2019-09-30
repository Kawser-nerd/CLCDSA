import java.util.*;

public class Main {

    void run() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        if (n == 4) {
            System.out.println(4);
            System.out.println(1 + " " + 2);
            System.out.println(1 + " " + 3);
            System.out.println(4 + " " + 2);
            System.out.println(4 + " " + 3);
            return;
        } else if (n == 3) {
          System.out.println(2);
            System.out.println(3 + " " + 1);
            System.out.println(3 + " " + 2);
            return;
        }

        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        if (n % 2 == 1) {
            ArrayList<Integer> a = new ArrayList<>();
            a.add(n);
            ans.add(a);
            n--;
        }
        for (int i = 1; i <= n / 2; i++) {
            ArrayList<Integer> a = new ArrayList<>();
            a.add(i); a.add(n - i + 1);
            ans.add(a);
        }

        int len = ans.size();
        int m = 0;
        for (int i = 0; i < len; i++) {
            m += ans.get(i).size() * ans.get((i + 1) % len).size();
        }

        System.out.println(m);
        for (int i = 0; i < len; i++) {
            for (int j: ans.get(i)) for (int k: ans.get((i + 1) % len)) {
                System.out.println(j + " " + k);
            }
        }
    }

    // 1 2 3 4 5

    void debug(Object...os) {
        System.err.println(Arrays.deepToString(os));
    }

    public static void main(String[] args) {
        new Main().run();
    }
}