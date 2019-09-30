import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

/**
 * Created by darshan on 4/3/19.
 * https://atcoder.jp/contests/arc080/tasks/arc080_c
 */
public class Main {
    private static int n;
    private static int[] sequence;
    private static int[] indexInSequence;

    private static int[] minEvenElementTree = new int[1000000];
    private static int[] minOddElementTree = new int[1000000];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());
        sequence = new int[n];
        indexInSequence = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            sequence[i] = Integer.parseInt(st.nextToken()) - 1;
            indexInSequence[sequence[i]] = i;
        }

        buildMinEvenElementTree(0, n - 1, 0);
        buildMinOddElementTree(0, n - 1, 0);

        int numElements = 0;
        int[] permutation = new int[n];
        PriorityQueue<Interval> priorityQueue = new PriorityQueue<>(n / 2);
        priorityQueue.add(createInterval(0, n - 1, true));
        while (!priorityQueue.isEmpty()) {
            Interval interval = priorityQueue.poll();
            permutation[numElements++] = interval.minFirstValue + 1;
            permutation[numElements++] = interval.minSecondValue + 1;

            int minFirstValueIndex = indexInSequence[interval.minFirstValue];
            int minSecondValueIndex = indexInSequence[interval.minSecondValue];
            if (minFirstValueIndex - interval.start > 1) {
                priorityQueue.add(createInterval(
                        interval.start, minFirstValueIndex - 1, interval.evenFirst));
            }
            if (minSecondValueIndex - minFirstValueIndex > 1) {
                priorityQueue.add(createInterval(
                        minFirstValueIndex + 1, minSecondValueIndex -1, !interval.evenFirst));
            }
            if (interval.end - minSecondValueIndex > 1) {
                priorityQueue.add(createInterval(
                        minSecondValueIndex + 1, interval.end, interval.evenFirst));
            }
        }

        for (int num : permutation) {
            out.print(num + " ");
        }
        out.close();
    }

    private static int buildMinEvenElementTree(int start, int end, int index) {
        if (start == end) {
            if (start % 2 == 0) {
                minEvenElementTree[index] = sequence[start];
            } else {
                minEvenElementTree[index] = Integer.MAX_VALUE;
            }
            return minEvenElementTree[index];
        }

        int mid = (start + end) / 2;
        int leftMin = buildMinEvenElementTree(start, mid, 2 * index + 1);
        int rightMin = buildMinEvenElementTree(mid + 1, end, 2 * index + 2);
        minEvenElementTree[index] = Math.min(leftMin, rightMin);
        return minEvenElementTree[index];
    }

    private static int getMinEvenElement(int start, int end, int queryStart, int queryEnd, int index) {
        if (queryStart <= start && queryEnd >= end) {
            return minEvenElementTree[index];
        }
        if (queryStart > end || queryEnd < start) {
            return Integer.MAX_VALUE;
        }
        int mid = (start + end) / 2;
        int leftMin = getMinEvenElement(start, mid, queryStart, queryEnd, 2 * index + 1);
        int rightMin = getMinEvenElement(mid + 1, end, queryStart, queryEnd, 2 * index + 2);
        return Math.min(leftMin, rightMin);
    }

    private static int buildMinOddElementTree(int start, int end, int index) {
        if (start == end) {
            if (start % 2 == 1) {
                minOddElementTree[index] = sequence[start];
            } else {
                minOddElementTree[index] = Integer.MAX_VALUE;
            }
            return minOddElementTree[index];
        }

        int mid = (start + end) / 2;
        int leftMin = buildMinOddElementTree(start, mid, 2 * index + 1);
        int rightMin = buildMinOddElementTree(mid + 1, end, 2 * index + 2);
        minOddElementTree[index] = Math.min(leftMin, rightMin);
        return minOddElementTree[index];
    }

    private static int getMinOddElement(int start, int end, int queryStart, int queryEnd, int index) {
        if (queryStart <= start && queryEnd >= end) {
            return minOddElementTree[index];
        }
        if (queryStart > end || queryEnd < start) {
            return Integer.MAX_VALUE;
        }
        int mid = (start + end) / 2;
        int leftMin = getMinOddElement(start, mid, queryStart, queryEnd, 2 * index + 1);
        int rightMin = getMinOddElement(mid + 1, end, queryStart, queryEnd, 2 * index + 2);
        return Math.min(leftMin, rightMin);
    }

    private static Interval createInterval(int start, int end, boolean evenFirst) {
        Interval interval = new Interval(start, end, evenFirst);
        if (evenFirst) {
            interval.minFirstValue = getMinEvenElement(
                    0, n - 1, start, end, 0);
            interval.minSecondValue = getMinOddElement(
                    0, n - 1, indexInSequence[interval.minFirstValue] + 1, end, 0);
        } else {
            interval.minFirstValue = getMinOddElement(
                    0, n - 1, start, end, 0);
            interval.minSecondValue = getMinEvenElement(
                    0, n - 1, indexInSequence[interval.minFirstValue] + 1, end, 0);

        }
        return interval;
    }

    private static class Interval implements Comparable<Interval> {
        private int start;
        private int end;
        private boolean evenFirst;
        private int minFirstValue;
        private int minSecondValue;

        private Interval(int start, int end, boolean evenFirst) {
            this.start = start;
            this.end = end;
            this.evenFirst = evenFirst;
        }

        @Override
        public int compareTo(Interval o) {
            return this.minFirstValue - o.minFirstValue;
        }
    }
}