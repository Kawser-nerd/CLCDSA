import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {
    static int h;
    static int w;
    static int[][] a;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        h = sc.nextInt();
        w = sc.nextInt();

        a = new int[h][w];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                a[i][j] = sc.nextInt();
            }
        }

        List<String> ret = new ArrayList<>();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w - 1; j++) {
                if(a[i][j] % 2 == 0) {
                    continue;
                }
                a[i][j+1] += 1;
                ret.add(String.format("%d %d %d %d", i+1, j+1, i+1, j+2));
            }
        }
        for (int i = 0; i < h - 1; i++) {
            if(a[i][w-1] % 2 == 0) {
                continue;
            }
            a[i+1][w-1] += 1;
            ret.add(String.format("%d %d %d %d", i+1, w, i+2, w));
        }
        System.out.println(ret.size());
        ret.forEach(System.out::println);
    }
}