import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Objects;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Stream;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Comparator;
import java.util.ArrayList;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author mikit
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DRecording solver = new DRecording();
        solver.solve(1, in, out);
        out.close();
    }

    static class DRecording {
        private static final int CHANNELS = 30;

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            in.nextInt();
            DRecording.Program[] t = new DRecording.Program[n];
            for (int i = 0; i < n; i++) {
                t[i] = new DRecording.Program(in.nextInt(), in.nextInt(), in.nextInt() - 1);
            }
            Arrays.sort(t, Comparator.comparing(p -> p.start));

            List<DRecording.Program> programs = new ArrayList<>();
            DRecording.Program[] last = new DRecording.Program[CHANNELS];
            for (DRecording.Program p : t) {
                if (last[p.channel] != null) {
                    if (p.start - last[p.channel].end > 0) {
                        programs.add(last[p.channel]);
                        last[p.channel] = p;
                    } else {
                        last[p.channel] = new DRecording.Program(last[p.channel].start, p.end, p.channel);
                    }
                } else {
                    last[p.channel] = p;
                }
            }
            Arrays.stream(last).filter(Objects::nonNull).forEach(programs::add);
            programs.sort(Comparator.comparing(p -> p.start));

            List<Integer> recorders = new ArrayList<>();
            for (DRecording.Program p : programs) {
                Iterator<Integer> it = recorders.iterator();
                while (it.hasNext()) {
                    if (it.next() < p.start) {
                        it.remove();
                        break;
                    }
                }
                recorders.add(p.end);
            }
            out.println(recorders.size());
        }

        private static class Program {
            int channel;
            int start;
            int end;

            public Program(int start, int end, int channel) {
                this.channel = channel;
                this.start = start;
                this.end = end;
            }

            public String toString() {
                return "Program{" +
                        "channel=" + channel +
                        ", start=" + start +
                        ", end=" + end +
                        '}';
            }

        }

    }
}