package com.google.codejam2015.round1b;

import java.io.BufferedReader;
import java.io.Closeable;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.atomic.AtomicReferenceArray;

public class CountingCulture implements Closeable {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer = new PrintWriter(System.out);
    private final Object readLock = new Object();

    CountingCulture() throws IOException {
        reader = new BufferedReader(new FileReader("input.txt"));
        writer = new PrintWriter(new FileWriter("output.txt"));
    }

    StringTokenizer stringTokenizer;

    String next() throws IOException {
        synchronized (readLock) {
            while (stringTokenizer == null || !stringTokenizer.hasMoreTokens()) {
                stringTokenizer = new StringTokenizer(reader.readLine());
            }
            return stringTokenizer.nextToken();
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    void run() throws IOException, InterruptedException {
        int testsNumber = nextInt();
        final AtomicReferenceArray<String> answers = new AtomicReferenceArray<>(testsNumber);
        final AtomicInteger currentTest = new AtomicInteger(-1);
        abstract class Solver implements Runnable {
            @Override
            public final void run() {
                int testNumber;
                synchronized (readLock) {
                    testNumber = currentTest.incrementAndGet();
                    try {
                        readInput();
                    } catch (IOException e) {
                        throw new RuntimeException(e);
                    }
                }
                answers.set(testNumber, solve());
                System.out.println("Test " + testNumber + " complete");
            }

            abstract protected String solve();

            abstract protected void readInput() throws IOException;
        }
        final int availableProcessors = Runtime.getRuntime().availableProcessors();
        System.out.println("Number of available processors: " + availableProcessors);
        final ExecutorService executorService = Executors.newFixedThreadPool(availableProcessors + 1);
        for(int i = 0; i < testsNumber; i++) {
            executorService.execute(new Solver() {
                long N;

                int solveSmall(int n, int size) {
                    int[] prev = new int[size];
                    class Utils {
                        int reverse(int x) {
                            List<Integer> list = new ArrayList<>();
                            while(x > 0) {
                                list.add(x % 10);
                                x /= 10;
                            }
                            for (Integer i : list) {
                                x *= 10;
                                x += i;
                            }
                            return x;
                        }
                    }
                    Utils utils = new Utils();
                    Queue<Integer> q = new LinkedList<>();
                    prev[1] = 1;
                    q.offer(1);
                    while(!q.isEmpty()) {
                        int x = q.poll();
                        int y = utils.reverse(x);
                        if(prev[y] == 0) {
                            prev[y] = x;
                            q.offer(y);
                        }
                        if(x + 1 < prev.length && prev[x + 1] == 0) {
                            prev[x + 1] = x;
                            q.offer(x + 1);
                        }
                    }
//                    for(int i = 2; i < prev.length; i++) {
//                        if(prev[i] != i - 1) {
//                            System.out.println(i);
//                        }
//                    }
                    int answer = 1;
                    while(n != 1) {
                        n = prev[n];
                        answer++;
                    }
                    return answer;
                }

                @Override
                protected String solve() {
                    long answer = 0;
                    int sz = 1000;
                    class Utils {
                        int length(long x) {
                            int ret = 0;
                            for(; x > 0; x /= 10) {
                                ret++;
                            }
                            return ret;
                        }
                        long foo(long x) {
                            int l = length(x);
                            int cut = l + 1 >> 1;
                            int p10 = 1;
                            for(int i = 0; i < cut; i++) {
                                p10 *= 10;
                            }
                            x = x / p10 * p10;
                            return x + 1;
                        }

                        long nines(long x) {
                            int l = length(x);
                            long nines = 0;
                            for(int i = 0; i < l - 1; i++) {
                                nines *= 10;
                                nines += 9;
                            }
                            return nines;
                        }
                        long reverse(long x) {
                            List<Long> list = new ArrayList<>();
                            while(x > 0) {
                                list.add(x % 10);
                                x /= 10;
                            }
                            for (long i : list) {
                                x *= 10;
                                x += i;
                            }
                            return x;
                        }
                    }
                    long x = N;
                    Utils utils = new Utils();
                    while(x >= sz) {
                        long foo = utils.foo(x);
                        if(foo > x) {
                            x--;
                            answer++;
                            continue;
                        }
                        if(foo == utils.reverse(foo)) {
                            foo = utils.nines(x);
                            answer += x - foo;
                            x = foo;
                        } else {
                            answer += x - foo + 1;
                            x = utils.reverse(foo);
                        }
                    }
                    answer += solveSmall((int)x, sz);
                   /* if(N < 1000000) {
                        int answer2 = solveSmall((int)N, 10 * 1000 * 1000);
                        if(answer != answer2) {
                            throw new RuntimeException("failed for " + N);
                        }
                    }*/
                    return Long.toString(answer);
                }

                @Override
                protected void readInput() throws IOException {
                    N = nextLong();
                }
            });
        }
        executorService.shutdown();
        executorService.awaitTermination(10, TimeUnit.MINUTES);
        for(int i = 0; i < testsNumber; i++) {
            writer.println(String.format("Case #%d: %s", i + 1, answers.get(i)));
        }
    }

    public static void main(String[] args) throws IOException, InterruptedException {
        try(CountingCulture a = new CountingCulture()) {
            a.run();
        }
    }

    @Override
    public void close() throws IOException {
        reader.close();
        writer.close();
    }
}
