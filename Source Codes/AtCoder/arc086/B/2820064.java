import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        LinkedList<Integer> list = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            list.add(sc.nextInt());
        }

        int max = list.stream().max((o1, o2) -> o1 - o2).get();
        int min = list.stream().min((o1, o2) -> o1 - o2).get();

        if (max == min) {
            System.out.println(0);
        } else {
            if (min >= 0) {
                System.out.println(n - 1);
                for (int i = 1; i < n; i++) {
                    System.out.println(i + " " + (i + 1));
                }
            } else if (max <= 0) {
                System.out.println(n - 1);
                for (int i = n; i > 1; i--) {
                    System.out.println(i + " " + (i - 1));
                }
            } else {
                if (Math.abs(min) <= Math.abs(max)) {
                    int p = list.indexOf(max) + 1;

                    System.out.println(2 * (n - 1));
                    for (int i = 1; i <= n; i++) {
                        if (p == i) {
                            continue;
                        }
                        System.out.println(p + " " + i);
                    }
                    for (int i = 1; i < n; i++) {
                        System.out.println(i + " " + (i + 1));
                    }
                } else {
                    int p = list.indexOf(min) + 1;

                    System.out.println(2 * (n - 1));
                    for (int i = 1; i <= n; i++) {
                        if (p == i) {
                            continue;
                        }
                        System.out.println(p + " " + i);
                    }
                    for (int i = n; i > 1; i--) {
                        System.out.println(i + " " + (i - 1));
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}