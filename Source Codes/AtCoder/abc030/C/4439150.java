import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.*;

class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(in, out);
        out.close();
    }

    static class AirPort {
        private int curIndex;
        private int depTimes[];
        private int numOfPlains;
        private int timeTookToOtherAirPort;

        AirPort(int depTimes[], int timeTookToOtherAirPort) {
            this.curIndex = 0;
            this.depTimes = depTimes;
            this.numOfPlains = depTimes.length;
            this.timeTookToOtherAirPort = timeTookToOtherAirPort;
        }

        private int getNextPlainDepTime(int curTime) {
            while (curIndex < numOfPlains - 1 && depTimes[curIndex] < curTime) {
                ++curIndex;
            }
            return  depTimes[curIndex] < curTime ? -1 : depTimes[curIndex];
        }

        int getArrivalTimeAtOtherAirPort(int curTime) {
            int nextPlainDepTime = getNextPlainDepTime(curTime);
            return nextPlainDepTime > 0 ? nextPlainDepTime + timeTookToOtherAirPort : -1;
        }
    }

    static class Task {
        void solve(InputReader in, PrintWriter out) {
            int N = in.nextInt();
            int M = in.nextInt();
            int X = in.nextInt();
            int Y = in.nextInt();
            int a[] = in.nextIntArray(N);
            int b[] = in.nextIntArray(M);

            AirPort airPortA = new AirPort(a, X);
            AirPort airPortB = new AirPort(b, Y);

            int ans = 0;
            int curTime = 0;
            while (curTime >= 0) {
                curTime = airPortA.getArrivalTimeAtOtherAirPort(curTime);
                if (curTime < 0) break;
                curTime = airPortB.getArrivalTimeAtOtherAirPort(curTime);
                if (curTime < 0) break;
                ++ans;
            }
            out.println(ans);
        }
    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            int[] arr = new int[n];
            for (int i = 0; i < n; ++i) arr[i] = this.nextInt();
            return arr;
        }
    }
}