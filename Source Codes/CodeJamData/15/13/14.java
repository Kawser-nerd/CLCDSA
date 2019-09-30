import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numCases = sc.nextInt();
        for (int caseNum = 1; caseNum <= numCases; caseNum++) {
            int N = sc.nextInt();
            int[] X = new int[N];
            int[] Y = new int[N];
            for (int i = 0; i < N; i++) {
                X[i] = sc.nextInt();
                Y[i] = sc.nextInt();
            }

            System.out.println("Case #" + caseNum + ":");
            for (int i = 0; i < N; i++) {
                System.out.println(solve(N, X, Y, i));
            }
        }
    }

    private static int solve(int N, int[] X, int[] Y, int i) {
        if (N <= 3) {
            return 0;
        }
        List<Direction> directions = new ArrayList<Direction>();
        for (int j = 0; j < N; j++) {
            if (j == i) {
                continue;
            }
            directions.add(Direction.create(X[j] - X[i], Y[j] - Y[i]));
        }
        Collections.sort(directions);
        int min = N;

        int oppIndex = 0;
        Direction target = directions.get(0).opposite();
        while (oppIndex < directions.size() && inLeftHalfPlane(directions.get(0), directions.get(oppIndex))) {
            oppIndex++;
        }
        if (oppIndex == directions.size()) {
            return 0;
        }
        min = Math.min(min, oppIndex - 1);
        if (min == 0) {
            return 0;
        }
        for (int j = 1; j < directions.size(); j++) {
            for (int k = 0; k < directions.size(); k++) {
                if (inLeftHalfPlane(directions.get(j), directions.get(oppIndex))) {
                    oppIndex = (oppIndex + 1) % directions.size();
                } else {
                    break;
                }
            }
            min = Math.min(min, (oppIndex - j - 1 + directions.size()) % directions.size());
            if (min == 0) {
                return 0;
            }
        }
        return min;
    }

    static boolean inLeftHalfPlane(Direction dir1, Direction dir2) {
        if (dir1.equals(dir2)) {
            return true;
        }
        return (dir2.y * dir1.x - dir2.x * dir1.y) > 0;
    }

    private static class Direction implements Comparable<Direction> {
        long x;
        long y;

        private Direction(long x, long y) {
            this.x = x;
            this.y = y;
        }

        static Direction create(long xDiff, long yDiff) {
            long gcd = gcd(Math.abs(xDiff), Math.abs(yDiff));
            return new Direction(xDiff / gcd, yDiff / gcd);
        }

        private int quadrant() {
            if (x >= 0) {
                if (y >= 0) {
                    return 1;
                } else {
                    return 4;
                }
            } else {
                if (y < 0) {
                    return 3;
                } else {
                    return 2;
                }
            }
        }

        Direction opposite() {
            return new Direction(-x, -y);
        }

        @Override
        public int compareTo(Direction o) {
            if (this.equals(o)) {
                return 0;
            }
            if (this.quadrant() != o.quadrant()) {
                return this.quadrant() - o.quadrant();
            }
            if (inLeftHalfPlane(this, o)) {
                return -1;
            } else {
                return 1;
            }
        }

        @Override
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * result + (int) (x ^ (x >>> 32));
            result = prime * result + (int) (y ^ (y >>> 32));
            return result;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) {
                return true;
            }
            if (obj == null) {
                return false;
            }
            if (getClass() != obj.getClass()) {
                return false;
            }
            Direction other = (Direction) obj;
            if (x != other.x) {
                return false;
            }
            if (y != other.y) {
                return false;
            }
            return true;
        }

        @Override
        public String toString() {
            return "Direction [x=" + x + ", y=" + y + "]";
        }
    }

    private static long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
