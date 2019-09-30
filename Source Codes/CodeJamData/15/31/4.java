package round1c;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;

public class A {
    public static void main(String[] args) throws FileNotFoundException {
        Kattio io;

//        io = new Kattio(System.in, System.out);
//        io = new Kattio(new FileInputStream("round1c/A-sample.in"), System.out);
//        io = new Kattio(new FileInputStream("round1c/A-small-attempt0.in"), new FileOutputStream("round1c/A-small-0.out"));
        io = new Kattio(new FileInputStream("round1c/A-large.in"), new FileOutputStream("round1c/A-large-0.out"));

        int cases = io.getInt();
        for (int i = 1; i <= cases; i++) {
            io.print("Case #" + i + ": ");
            new A().solve(io);
        }
        io.close();
    }

    private int firstHit(int left, int right, int hit, int w) {
        if (hit == left || hit == right-1) {
            return w-1;
        }
        return w;
    }

    private void solve(Kattio io) {
        int rows = io.getInt(), cols = io.getInt(), w = io.getInt();
        int misses = (rows - 1) * (cols / w);
        int a = Integer.MAX_VALUE;
        for (int offset = 0; offset < w; offset++) {
            int cur = misses, leftBoundary = 0;
            int b = 0;
            for (int x = offset; x < cols; x+=w) {
                b = Math.max(b, cur + 1 + firstHit(leftBoundary, cols, x, w));
                cur++;
                leftBoundary = x + 1;
            }
            a = Math.min(a, b);
        }
        io.println(a);
    }
}
