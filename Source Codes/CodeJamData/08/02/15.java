import java.util.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;

/**
 * @author Dmitry Shyshkin
 */
public class Main {
    private static class Train implements Comparable<Train> {
        private int start;
        private int end;

        public Train(int start, int end) {
            this.start = start;
            this.end = end;
        }

        public int compareTo(Train o) {
            return start - o.start;
        }
    }

    private static class TimePoint implements Comparable<TimePoint> {
        private int time;

        private TimePoint(int time) {
            this.time = time;
        }

        public int compareTo(TimePoint o) {
            int i = time - o.time;
            return i != 0 ? i : System.identityHashCode(this) - System.identityHashCode(o) ;
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        String fname = "B-large";
        Scanner scanner = new Scanner(new File(fname + ".in"));
        PrintStream out = new PrintStream(fname + ".out");
        scanner.useDelimiter("[\\n\\r\\s]+");
        int n = scanner.nextInt();
        for (int num = 0; num < n; ++num) {
            int t = scanner.nextInt();
            int na = scanner.nextInt();
            int nb = scanner.nextInt();
            List<Train> a = new ArrayList<Train>(na);
            for (int i = 0; i < na; ++i) {
                a.add(parseTrain(scanner.next(), scanner.next()));
            }
            List<Train> b = new ArrayList<Train>(nb);
            for (int i = 0; i < nb; ++i) {
                b.add(parseTrain(scanner.next(), scanner.next()));
            }
            Collections.sort(a);
            Collections.sort(b);

            SortedSet<TimePoint> traina = new TreeSet<TimePoint>();
            SortedSet<TimePoint> trainb = new TreeSet<TimePoint>();

            int atotal = 0;
            int btotal = 0;

            int i = 0, j = 0;
            while (i < na || j < nb) {
                long astart = i != na ? a.get(i).start : Integer.MAX_VALUE;
                long bstart = j != nb ? b.get(j).start : Integer.MAX_VALUE;
                if (astart <= bstart) {
                    //a
                    if (traina.size() > 0 && traina.first().time <= astart) {
                        traina.remove(traina.first());
                    } else {
                        ++atotal;
                    }
                    trainb.add(new TimePoint(a.get(i).end + t));
                    ++i;
                } else {
                    //b
                    if (trainb.size() > 0 && trainb.first().time <= bstart) {
                        trainb.remove(trainb.first());
                    } else {
                        ++btotal;
                    }
                    traina.add(new TimePoint(b.get(j).end + t));
                    ++j;
                }
            }
            System.out.printf("Case #%d: %d %d\n", num + 1, atotal, btotal);
            out.printf("Case #%d: %d %d\n", num + 1, atotal, btotal);
        }
        scanner.close();
        out.close();
    }

    private static int parseDate(String value) {
        String[] v = value.split(":");
        return Integer.parseInt(v[0]) * 60 + Integer.parseInt(v[1]);
    }

    private static Train parseTrain(String start, String end) {
        return new Train(parseDate(start), parseDate(end));
    }

}
