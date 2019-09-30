import java.util.*;

public class Main {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int A = scanner.nextInt();
            int B = scanner.nextInt();
            int Q = scanner.nextInt();

            NavigableSet<Long> temples = new TreeSet<>();
            NavigableSet<Long> shrines = new TreeSet<>();
            for (int i = 0; i < A; i++) {
                shrines.add(scanner.nextLong());
            }
            for (int i = 0; i < B; i++) {
                temples.add(scanner.nextLong());
            }
            for (int i = 0; i < Q; i++) {
                long startPos = scanner.nextLong();
                long min = Math.min(dist(shrines, temples, startPos), dist(temples, shrines, startPos));
                System.out.println(min);
            }
        }
    }

    static long dist(NavigableSet<Long> set1, NavigableSet<Long> set2, long pos) {
        long min = Long.MAX_VALUE;
        Pair pair1 = closestDist(set1, pos);
        if (pair1.left != null) {
            Pair second = closestDist(set2, pair1.left);
            long firstStep = Math.abs(pos - pair1.left);
            if (second.left != null) {
                long dist = firstStep + Math.abs(second.left - pair1.left);
                min = Math.min(dist, min);
            }
            if (second.right != null) {
                long dist = firstStep + Math.abs(second.right - pair1.left);
                min = Math.min(dist, min);
            }
        }
        if (pair1.right != null) {
            Pair second = closestDist(set2, pair1.right);
            long firstStep = Math.abs(pos - pair1.right);
            if (second.left != null) {
                long dist = firstStep + Math.abs(second.left - pair1.right);
                min = Math.min(dist, min);
            }
            if (second.right != null) {
                long dist = firstStep + Math.abs(second.right - pair1.right);
                min = Math.min(dist, min);
            }
        }
        return min;
    }

    static Pair closestDist(NavigableSet<Long> set, long pos) {
        Long ceiling = set.ceiling(pos);
        Long floor = set.floor(pos);
        return new Pair(floor, ceiling);
    }

    static class Pair {
        final Long left;
        final Long right;

        Pair(Long left, Long right) {
            this.left = left;
            this.right = right;
        }
    }

}