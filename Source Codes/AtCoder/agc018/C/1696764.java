import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int nGold = in.nextInt();
            int nSilver = in.nextInt();
            int nBronze = in.nextInt();

            int n = nGold + nSilver + nBronze;
            Person[] people = new Person[n];
            for (int i = 0; i < n; i++) {
                people[i] = new Person(in.nextInt(), in.nextInt(), in.nextInt());
            }

            Arrays.sort(people, Comparator.comparingInt(p -> p.gold - p.silver));

            long[] maxSilverBronze = new long[nBronze + 1];
            {
                long sumSilver = 0;
                long sumBronze = 0;
                PriorityQueue<Person> queue = new PriorityQueue<>(Comparator.comparingInt(p -> p.silver - p.bronze));
                for (int i = 0; i < nSilver; i++) {
                    sumSilver += people[i].silver;
                    queue.add(people[i]);
                }
                maxSilverBronze[0] = sumSilver;
                for (int i = 0; i < nBronze; i++) {
                    sumSilver += people[nSilver + i].silver;
                    queue.add(people[nSilver + i]);
                    Person person = queue.poll();
                    sumSilver -= person.silver;
                    sumBronze += person.bronze;
                    maxSilverBronze[i + 1] = sumSilver + sumBronze;
                }
            }

            for (int i = 0; i < n / 2; i++) {
                Person tmp = people[i];
                people[i] = people[n - 1 - i];
                people[n - 1 - i] = tmp;
            }
            long[] maxGoldBronze = new long[nBronze + 1];
            {
                long sumGold = 0;
                long sumBronze = 0;
                PriorityQueue<Person> queue = new PriorityQueue<>(Comparator.comparingInt(p -> p.gold - p.bronze));
                for (int i = 0; i < nGold; i++) {
                    sumGold += people[i].gold;
                    queue.add(people[i]);
                }
                maxGoldBronze[0] = sumGold;
                for (int i = 0; i < nBronze; i++) {
                    sumGold += people[nGold + i].gold;
                    queue.add(people[nGold + i]);
                    Person person = queue.poll();
                    sumGold -= person.gold;
                    sumBronze += person.bronze;
                    maxGoldBronze[i + 1] = sumGold + sumBronze;
                }
            }

            long ans = 0;
            for (int i = 0; i <= nBronze; i++) {
                ans = Math.max(ans, maxSilverBronze[i] + maxGoldBronze[nBronze - i]);
            }

            out.println(ans);
        }

        class Person {
            int gold;
            int silver;
            int bronze;

            public Person(int gold, int silver, int bronze) {
                this.gold = gold;
                this.silver = silver;
                this.bronze = bronze;
            }

        }

    }

    static class InputReader {
        BufferedReader in;
        StringTokenizer tok;

        public String nextString() {
            while (!tok.hasMoreTokens()) {
                try {
                    tok = new StringTokenizer(in.readLine(), " ");
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }
            return tok.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextString());
        }

        public InputReader(InputStream inputStream) {
            in = new BufferedReader(new InputStreamReader(inputStream));
            tok = new StringTokenizer("");
        }

    }
}