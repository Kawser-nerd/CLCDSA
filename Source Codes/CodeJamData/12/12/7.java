import java.util.*;
import java.math.*;

public class Main {
    
    static class Level implements Comparable<Level> {
        public int low;
        public int high;
        public Level(int low, int high) {
            this.low = low;
            this.high = high;
        }

        @Override
        public int compareTo(Level o) {
            return high - o.high;
        }
    }
    
    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(System.in);
        int task = scan.nextInt();
        int current = 1;
        while(task-- > 0)
        {
            int N = scan.nextInt();
            Level[] arr = new Level[N];
            int[] status = new int[N];
            int finished = 0;
            int star = 0;
            for (int i = 0; i < N; i++) {
                arr[i] = new Level(scan.nextInt(), scan.nextInt());
            }
            Arrays.sort(arr);
            int result = 0;
            while (finished < N) {
                for (int i = 0; i < N; i++) {
                    if (status[i] == 2) {
                        continue;
                    }
                    if (star >= arr[i].high) {
                        star += 2 - status[i];
                        status[i] = 2;
                        finished++;
                        result++;
                    }
                }
                if (finished == N) {
                    break;
                }
                int select = -1;
                int max = -1;
                for (int i = 0; i < N; i++) {
                    if (status[i] >= 1) {
                        continue;
                    }
                    if (star >= arr[i].low) {
                        if (arr[i].high > max) {
                            select = i;
                            max = arr[i].high;
                        }
                    }
                }
                if (select == -1) {
                    result = -1;
                    break;
                }
                else {
                    result++;
                    status[select] = 1;
                    star++;
                }
            }
            System.out.println("Case #" + current + ": " + (result == -1 ? "Too Bad" : result));
            current++;
        }
    }
}