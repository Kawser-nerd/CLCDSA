import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextInt();
        }

        // 2???????????????
        Set<Integer> nums = new HashSet<Integer>();
        for (int i = 0; i < N; i++) {
            int num = a[i];
            while (num % 2 == 0) {
                num /= 2;
            }
            nums.add(num);
        }

        out.println(nums.size());
    }
}