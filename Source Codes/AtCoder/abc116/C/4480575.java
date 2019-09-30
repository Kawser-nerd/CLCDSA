import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int ans = 0;
        int N = in.nextInt();
        int[] values = new int[N];

        for (int i = 0; i < N; i++) {
            values[i] = in.nextInt();
        }
        // ??????0????
        int[] valuesWithPadding = new int[N+2];
        for (int i = 0; i < N; i++) {
            valuesWithPadding[i+1] = values[i];
        }

        while (true) {
            
            // 0?????????????
            int count = 0;
            for (int i = 1; i < N+2; i++) {
                if (valuesWithPadding[i] != 0) {
                    if (valuesWithPadding[i - 1] == 0) {
                        count++;
                    }
                }
            }
            if (count == 0) break;
            for (int i = 0; i < N+2; i++) {
                if (valuesWithPadding[i] != 0) {
                    valuesWithPadding[i] -= 1;
                }
            }
            ans += count;
        }
        System.out.println(ans);

    }

}