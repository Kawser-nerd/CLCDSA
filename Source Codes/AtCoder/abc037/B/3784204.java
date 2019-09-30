import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] nq = scanner.nextLine().split(" ", 2);
        int n = Integer.parseInt(nq[0]);
        int q = Integer.parseInt(nq[1]);

        int[] arr = new int[n];
        for (int i = 0; i < q; i++) {
            String[] lrt = scanner.nextLine().split(" ", 3);
            int l = Integer.parseInt(lrt[0]);
            int r = Integer.parseInt(lrt[1]);
            int t = Integer.parseInt(lrt[2]);

            for (int j = l - 1; j < r; j++) {
                arr[j] = t;
            }
        }

        for (int i = 0; i < n; i++) {
            System.out.println(arr[i]);
        }
    }
}