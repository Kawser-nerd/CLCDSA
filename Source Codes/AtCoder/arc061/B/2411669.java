import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long h = in.nextLong(), w = in.nextLong();
        int n = in.nextInt();
        Map<Long, Integer> map = new HashMap<>();
        int[] dx = {0, 0, 1, 1, 1, 0, -1, -1, -1};
        int[] dy = {0, -1, -1, 0, 1, 1, 1, 0, -1};
        for(int i = 0; i < n; i++) {
            int a = in.nextInt() - 1, b = in.nextInt() - 1;
            for(int k = 0; k < 9; k++) {
                int y = a + dy[k], x = b + dx[k];
                if(x < 1 || w-1 <= x || y < 1 || h-1 <= y) {
                    continue;
                }
                long key = (long)y<<32|x;
                Integer val = map.get(key);
                map.put(key, val == null ? 1 : val + 1);
            }
        }
        System.out.println((h-2) * (w-2) - map.size());
        long[] cnt = new long[10];
        for(long key: map.keySet()) {
            cnt[map.get(key)]++;
        }
        for(int i = 1; i < 10; i++) {
            System.out.println(cnt[i]);
        }
    }
}