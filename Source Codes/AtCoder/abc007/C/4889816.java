import java.awt.*;
import java.util.*;
import java.util.stream.IntStream;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        int r = scanner.nextInt(), c = scanner.nextInt();
        Point start = new Point(scanner.nextInt() - 1, scanner.nextInt() - 1);
        Point goal = new Point(scanner.nextInt() - 1, scanner.nextInt() - 1);
        int[][] a = IntStream.range(0, r).mapToObj(j -> scanner.next().chars().map(ch -> ch == '#' ? -1 : 0).toArray()).toArray(int[][]::new);
        Queue<Point> queue = new ArrayDeque<>();
        a[start.x][start.y]++;
        queue.add(start);
        while (!queue.isEmpty()) {
            Point point = queue.poll();
            for (int i = 0; i < 4; i++) {
                try {
                    int x1 = (new int[] {-1, 1, 0, 0})[i], y1 = (new int[] {0, 0, -1, 1})[i];
                    if (a[point.x + x1][point.y + y1] > a[point.x][point.y] + 1 || a[point.x + x1][point.y + y1] == 0) {
                        a[point.x + x1][point.y + y1] = a[point.x][point.y] + 1;
                        queue.add(new Point(point.x + x1, point.y + y1));
                    }
                } catch (ArrayIndexOutOfBoundsException e) {}
            }
        }

        System.out.println(a[goal.x][goal.y] - 1);
    }
}