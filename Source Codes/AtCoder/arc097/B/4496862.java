import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import static java.util.stream.Collectors.toList;
import static java.util.stream.IntStream.range;

public class Main {
    public static String process(TestCase testCase) {
        final int N = testCase.N;
        final int M = testCase.M;
        final List<Integer> p = testCase.p;
        final List<Integer> x = testCase.x;
        final List<Integer> y = testCase.y;

        DisjointSet disjointSet = DisjointSet.buildDisjointSet(N, M, x, y);

        return String.valueOf(range(0, N).filter(i -> disjointSet.areInSameSet(i + 1, p.get(i))).count());
    }

    private static class DisjointSet {
        private final List<DisjointSetTree> trees;

        DisjointSet(List<DisjointSetTree> trees) {
            this.trees = trees;
        }

        boolean areInSameSet(int x, int y) {
            return trees.get(x).isInSameSet(trees.get(y));
        }

        static DisjointSet buildDisjointSet(int N, int M, List<Integer> x, List<Integer> y) {
            final List<DisjointSetTree> trees = range(0, N + 1).mapToObj(i -> new DisjointSetTree()).collect(toList());
            range(0, M).forEach(i -> {
                final int xi = x.get(i);
                final int yi = y.get(i);

                trees.get(xi).union(trees.get(yi));
            });

            return new DisjointSet(trees);
        }

        private static class DisjointSetTree {
            DisjointSetTree parent = this;
            int rank = 0;

            // Find, with path-compression
            // Reference: https://en.wikipedia.org/wiki/Disjoint-set_data_structure#Path_compression
            DisjointSetTree find() {
                if (this.parent != this) {
                    this.parent = parent.find();
                }
                return this.parent;
            }

            // Union, by-rank
            // Reference: https://en.wikipedia.org/wiki/Disjoint-set_data_structure#by_rank
            void union(DisjointSetTree other) {
                DisjointSetTree xRoot = find();
                DisjointSetTree yRoot = other.find();
                if (xRoot != yRoot) {
                    if (xRoot.rank < yRoot.rank) {
                        DisjointSetTree temp = xRoot;
                        // swapping in Java, sigh
                        //noinspection SuspiciousNameCombination
                        xRoot = yRoot;
                        yRoot = temp;
                    }
                    yRoot.parent = xRoot;
                    if (xRoot.rank == yRoot.rank) {
                        xRoot.rank = xRoot.rank + 1;
                    }
                }
            }

            boolean isInSameSet(DisjointSetTree other) {
                return find() == other.find();
            }
        }
    }

    // Util func

    public static void main(String[] args) {
        TestCase testCase = readFromInput();

        final String result = process(testCase);

        output(result);
    }

    private static TestCase readFromInput() {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();

        List<Integer> p = readList(sc, N);

        List<Integer> x = new ArrayList<>();
        List<Integer> y = new ArrayList<>();
        range(0, M).forEach(i -> {
            x.add(sc.nextInt());
            y.add(sc.nextInt());
        });

        return new TestCase(N, M, p, x, y);
    }

    private static List<Integer> readList(Scanner sc, int N) {
        return range(0, N).mapToObj(i -> sc.nextInt()).collect(toList());
    }

    private static void output(String result) {
        System.out.println(result);
    }

    public static class TestCase {
        final int N;
        final int M;
        final List<Integer> p;
        final List<Integer> x;
        final List<Integer> y;

        public TestCase(int N, int M, List<Integer> p, List<Integer> x, List<Integer> y) {
            this.N = N;
            this.M = M;
            this.p = p;
            this.x = x;
            this.y = y;
        }
    }
}