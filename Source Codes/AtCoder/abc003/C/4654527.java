import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            list.add(x);
        }

        list.sort(Comparator.naturalOrder());

        double ans = 0;
        for(int i=n-m; i<n; i++) {
            ans = (ans + list.get(i)) / 2.0;
        }
        System.out.println(ans);
    }
}