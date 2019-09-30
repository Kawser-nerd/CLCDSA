import java.util.*;

public class Main {
    private static final double INF = Double.MAX_VALUE;

    class Circle {
        int x, y, r;
        Double minCost = INF;
        boolean visit;
        List<Road> child = new ArrayList<>();

        public Circle(int x, int y, int r) {
            this.x = x;
            this.y = y;
            this.r = r;
            visit = false;
        }
    }

    class Road {
        int src, dst;
        double cost;

        public Road(int src, int dst, double cost) {
            this.src = src;
            this.dst = dst;
            this.cost = cost;
        }
    }

    public void main(Scanner sc) {
        Circle s = new Circle(sc.nextInt(), sc.nextInt(), 0);
        Circle t = new Circle(sc.nextInt(), sc.nextInt(), 0);
        int n = sc.nextInt();
        Circle c[] = new Circle[n + 2];
        c[0] = s;
        for (int i = 1; i <= n; i++) {
            c[i] = new Circle(sc.nextInt(), sc.nextInt(), sc.nextInt());
        }
        c[n + 1] = t;
        sc.close();

        for (int i = 0; i < n + 2; i++) {
            for (int j = i + 1; j < n + 2; j++) {
                double len = getLength(c[i], c[j]);
                c[i].child.add(new Road(i, j, len));
                c[j].child.add(new Road(j, i, len));
            }
        }

        c[0].minCost = 0.0;
        Queue<Circle> queue = new PriorityQueue<>((o1, o2) -> o1.minCost.compareTo(o2.minCost));
        queue.add(c[0]);
        while (!queue.isEmpty()) {
            Circle tmp = queue.poll();
            if (tmp.visit) {
                continue;
            }

            tmp.visit = true;
            for (Road r : tmp.child) {
                if (c[r.dst].visit) {
                    continue;
                }

                c[r.dst].minCost = Math.min(c[r.dst].minCost, tmp.minCost + r.cost);
                queue.add(c[r.dst]);
            }
        }

        System.out.println(String.format("%.10f", c[n + 1].minCost));
    }

    private double getLength(Circle c1, Circle c2) {
        return Math.max(Math.hypot(c1.x - c2.x, c1.y - c2.y) - c1.r - c2.r, 0);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
    }
}