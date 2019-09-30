package year2009.round1B.c;


import java.io.*;
import java.util.*;

public class ProblemCTest implements Runnable {
    public static final String FILE_PREFIX = "C";
    private Map<Pair, Integer> cache;


    public void run() {

        try {
            Scanner in = new Scanner(new BufferedReader(new FileReader(getInputFile())));
            PrintWriter out = new PrintWriter("output-"  + FILE_PREFIX + "test.txt");
            int COUNT = in.nextInt();

            for (int pass = 0; pass < COUNT; pass ++) {
                cache = new HashMap<Pair, Integer>();
                int N = in.nextInt();
                int K = in.nextInt();
                int[] pr = new int[K];
                for (int i = 0; i < pr.length; i++) {
                    pr[i] = in.nextInt();
                }
                Arrays.sort(pr);
//                System.out.println("Case  " +  (pass + 1));
//                System.out.println("k= " +  K);
//                System.out.println(Arrays.toString(pr)+ " of " + N);
                ArrayList<Integer> prar = new ArrayList<Integer>();
                for (int i = 0; i < pr.length; i++) {
                    prar.add(pr[i]);

                }
                int ans = find(prar, 1, N);

                out.printf("Case #%d: ", pass + 1);
                System.out.println(ans);
                out.print(ans);
                out.println();
            }




            out.close();
            in.close();
        } catch (Throwable e) {
            e.printStackTrace();
        }
    }


    private int find(List<Integer> prar, int l, int r) {
        if (prar.size() == 0) {
            return 0;
        }
        Pair p = new Pair(l,r);
        if (cache.containsKey(p))  {
            return cache.get(p);
        }
        int best = Integer.MAX_VALUE / 100;
        int bestPos = 0;
        for (int j = 0; j < prar.size(); j++) {
            int prisoner = prar.get(j);
            int attempt = find(prar.subList(0, j), l, prisoner - 1) + find(prar.subList(j + 1, prar.size()), prisoner + 1, r);
            if (attempt < best) {
                best = attempt;
                bestPos = prisoner;
            }

        }
//        System.out.println("Split at " + bestPos + " for total " + (best + r - l)+ " with " + prar);
        int result = best + r - l;
        cache.put(p, result);
        return result;
    }


    public static void main(String[] args) {
        new Thread(new ProblemCTest()).start();
    }

    public File getInputFile() {
        File result = null;
        File temp = new File("input" + FILE_PREFIX + ".txt");
        if (temp.exists())  {
            result = temp;
        }
        temp = new File(FILE_PREFIX + "-small-attempt.in");
        if (temp.exists())  {
            result = temp;
        }
        int index = 0;
        temp = new File(FILE_PREFIX + "-small-attempt" +index +  ".in");
        while (temp.exists())  {
            result = temp;
            index++;
            temp = new File(FILE_PREFIX + "-small-attempt" +index +  ".in");
        }
        temp = new File(FILE_PREFIX + "-large.in");
        if (temp.exists())  {
            result = temp;
        }
        System.out.println("Using " + result);
        return result;
    }
    private static class Pair {
        int l;
        int r;

        private Pair(int l, int r) {
            this.l = l;
            this.r = r;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Pair pair = (Pair) o;

            if (l != pair.l) return false;
            if (r != pair.r) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = l;
            result = 31 * result + r;
            return result;
        }
    }

}