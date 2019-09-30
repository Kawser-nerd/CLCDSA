import java.util.*;

import static java.lang.System.*;

// ???????(LIS: Longest Increasing Subsequence)
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] c = new int[N];
        for (int i = 0; i < N; i++) c[i] = sc.nextInt();

        // LIS
        int[] LIS = new int[N];
        int INTMAX = 100000;
        Arrays.fill(LIS, INTMAX);

        for (int i = 0; i < N; i++){
            int numi = c[i];

            int insertionPoint = binarySearch (LIS, numi);
            LIS[insertionPoint] = Math.min(LIS[insertionPoint], numi);
            //out.println(Arrays.toString(LIS));
        }

        int maxSortedCount = binarySearch(LIS, INTMAX - 1);
        //out.println(maxSortedCount);
        out.println(N-maxSortedCount);
    }

    // https://qiita.com/taskie/items/b4e45e2005aa38e90bcb
    public static int binarySearch(int[] LTS, int num){
        int result = Arrays.binarySearch(LTS, num);
        return (result >= 0) ? result : ~result;
    }
}