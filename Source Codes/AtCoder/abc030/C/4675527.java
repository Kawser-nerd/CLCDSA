import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int X = sc.nextInt();
        int Y = sc.nextInt();

        int[] a = new int[N];
        int[] b = new int[M];
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextInt();
        }
        for (int i = 0; i < M; i++) {
            b[i] = sc.nextInt();
        }

        int ans = 0;
        int time = 0;
        while (true) {
            int aIndex = binarySearch(a, time);
            if(aIndex >= N){ break; }
            time = a[aIndex] + X;

            int bIndex = binarySearch(b, time);
            if(bIndex >= M){ break; }
            time = b[bIndex] + Y;

            ans++;
        }

        out.println(ans);
    }

    // https://qiita.com/taskie/items/b4e45e2005aa38e90bcb
    public static int binarySearch(int[] arr, int num) {
        int result = Arrays.binarySearch(arr, num);
        return (result >= 0) ? result : ~result;
    }
}