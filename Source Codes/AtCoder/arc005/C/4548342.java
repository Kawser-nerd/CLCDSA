import java.util.*;

public class Main {
    private static class Human {
        int x, y, cnt;

        public Human(int x, int y, int cnt) {
            this.x = x;
            this.y = y;
            this.cnt = cnt;
        }
    }

    private int mx[] = { 1, 0, -1, 0 };
    private int my[] = { 0, 1, 0, -1 };

    public void main(Scanner sc) {
        int h = sc.nextInt();
        int w = sc.nextInt();
        int map[][] = new int[h][w];

        Queue<Human> queue = new ArrayDeque<>();
        int gx = -1, gy = -1;
        for (int i = 0; i < h; i++) {
            char s[] = sc.next().toCharArray();
            for (int j = 0; j < w; j++) {
                if (s[j] == '.') {
                    map[i][j] = 0;
                } else if (s[j] == 's') {
                    queue.add(new Human(j, i, 0));
                } else if (s[j] == 'g') {
                    gx = j;
                    gy = i;
                } else {
                    map[i][j] = -1;
                }
            }
        }

        int data[][] = new int[h][w];
        for (int i = 0; i < h; i++) {
            Arrays.fill(data[i], 3);
        }
        while (!queue.isEmpty()) {
            Human human = queue.poll();
            if (data[human.y][human.x] <= human.cnt) {
                continue;
            }
            if (human.x == gx && human.y == gy) {
                System.out.println("YES");
                return;
            }

            if (map[human.y][human.x] == 0) {
                data[human.y][human.x] = human.cnt;
            }
            for (int i = 0; i < 4; i++) {
                int nx = human.x + mx[i];
                int ny = human.y + my[i];
                if (nx >= 0 && nx < w && ny >= 0 && ny < h && data[ny][nx] > human.cnt) {
                    if (map[ny][nx] == -1) {
                        if (human.cnt < 2) {
                            queue.add(new Human(nx, ny, human.cnt + 1));
                        }
                    } else {
                        queue.add(new Human(nx, ny, human.cnt));
                    }
                }
            }
        }

        System.out.println("NO");
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            new Main().main(sc);
        } catch (Exception e) {
            throw e;
        }
    }
}