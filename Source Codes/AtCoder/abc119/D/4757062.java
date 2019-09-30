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
            min = Math.min(min, dist2(set2, pair1.left, pos));
        }
        if (pair1.right != null) {
            min = Math.min(min, dist2(set2, pair1.right, pos));
        }
        return min;
    }

    static long dist2(NavigableSet<Long> set, Long secondPos, Long pos) {
        if (secondPos == null) {
            return Long.MAX_VALUE;
        }
        Pair second = closestDist(set, secondPos);
        long firstStep = Math.abs(pos - secondPos);
        long min = Long.MAX_VALUE;
        if (second.left != null) {
            long dist = firstStep + Math.abs(second.left - secondPos);
            min = Math.min(dist, min);
        }
        if (second.right != null) {
            long dist = firstStep + Math.abs(second.right - secondPos);
            min = Math.min(dist, min);
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