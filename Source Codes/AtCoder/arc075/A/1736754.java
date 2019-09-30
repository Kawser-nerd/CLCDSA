import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        List<Integer> list = new ArrayList<>();
        int ans = 0;
        for (int i = 0; i < N; i++) {
            int tmp = sc.nextInt();
            list.add(tmp);
            ans += tmp;
        }

        if (ans % 10 == 0) {
            Collections.sort(list);
            for (int i = 0; i < N; i++) {
                if ((ans - list.get(i)) % 10 != 0) {
                    ans = ans - list.get(i);
                    break;
                }
            }
        }

        if (ans % 10 == 0)
            System.out.println(0);
        else
            System.out.println(ans);
    }

}