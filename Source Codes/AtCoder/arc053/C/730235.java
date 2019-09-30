import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        Magic[] magics = new Magic[n];
        for (int i = 0; i < n; i++) {
            long a = sc.nextLong();
            long b = sc.nextLong();
            magics[i] = new Magic(a, b);
        }
        Arrays.sort(magics);
        long c = 0;
        long max = 0;
        // BigInteger c = new BigInteger("0");
        // BigInteger max = new BigInteger("0");
        for (Magic m : magics) {
            max = Math.max(max, c + m.up);
            // BigInteger mup = c.add(new BigInteger(String.valueOf(m.up)));
            // if (max.compareTo(mup) < 0) {
            //     max = mup;
            // }

            c += m.diff;
            // c = c.add(new BigInteger(String.valueOf(m.diff)));
            // System.out.println("c: " + m.up + ":" + m.down);
        }
        System.out.println(max);
    }

    static class Magic implements Comparable {
        public long up;
        public long down;
        public long diff;
        public int diffDir;

        Magic(long up, long down) {
            this.up = up;
            this.down = down;
            this.diff = up - down;
            this.diffDir = 0;
            if (this.diff > 0) {
                this.diffDir = 1;
            } else if (this.diff < 0){
                this.diffDir = -1;
            }
        }

        @Override
        public int compareTo(Object o) {
            Magic m = (Magic) o;
            int ddc = Integer.compare(this.diffDir, m.diffDir);
            if (ddc != 0) {
                return ddc;
            }
            if (m.diffDir > 0) {
                return -Long.compare(this.down, m.down);
            }
            return Long.compare(this.up, m.up);
        }
    }
}