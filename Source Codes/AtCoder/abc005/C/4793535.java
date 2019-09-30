import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int n = sc.nextInt();
        Integer[] takoyaki = new Integer[n];
        for (int i = 0; i < n; i++) {
            takoyaki[i] = sc.nextInt();
        }
        Arrays.sort(takoyaki, Comparator.naturalOrder());

        int m = sc.nextInt();
        Integer[] customer = new Integer[m];
        for (int i = 0; i < m; i++) {
            customer[i] = sc.nextInt();
        }
        Arrays.sort(customer, Comparator.naturalOrder());

        if (m > n) {
            System.out.println("no");
        } else {
            boolean check = true;
            int cnt = 0;
            for (int i = 0; i < m; i++) {
                if (cnt == n || !check) {
                    check = false;
                    break;
                }
                for (; cnt < n; cnt++) {
                    if (customer[i] - takoyaki[cnt] < 0) {
                        check = false;
                        cnt++;
                        break;
                    } else if(customer[i] - takoyaki[cnt] <= t) {
                        cnt++;
                        break;
                    } else if(cnt == n-1) {
                        check= false;
                    }
                }
            }

            if (check) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }
        }
    }
}