import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        // 30??????????
        N %= 30;

        int[] arr = {1, 2, 3, 4, 5, 6};
        for (int i = 0; i < N; i++) {
            int j1 = i % 5;
            int j2 = i % 5 + 1;

            int tmp = arr[j1];
            arr[j1] = arr[j2];
            arr[j2] = tmp;
        }
        StringBuilder builder = new StringBuilder();
        for(int num: arr){
            builder.append(num);
        }
        out.println(builder.toString());
    }
}