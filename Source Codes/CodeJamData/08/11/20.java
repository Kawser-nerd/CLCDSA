import java.io.*;
import java.util.*;

public class A {

    static void process(int c, BufferedReader in) throws IOException {
        int res = 0;
        in.readLine();
        String[] v = in.readLine().split(" ");
        LinkedList<Integer> xpos = new LinkedList<Integer>();
        LinkedList<Integer> xneg = new LinkedList<Integer>();
        for (String s : v) {
            int k = Integer.parseInt(s);
            if (k >= 0)
                xpos.add(k);
            if (k < 0)
                xneg.add(-k);
        }
        v = in.readLine().split(" ");
        LinkedList<Integer> ypos = new LinkedList<Integer>();
        LinkedList<Integer> yneg = new LinkedList<Integer>();
        for (String s : v) {
            int k = Integer.parseInt(s);
            if (k >= 0)
                ypos.add(k);
            if (k < 0)
                yneg.add(-k);
        }
        Collections.sort(xneg);
        Collections.sort(xpos);
        Collections.sort(yneg);
        Collections.sort(ypos);

        while (!xneg.isEmpty() && !ypos.isEmpty()) {
            res -= xneg.getLast() * ypos.getLast();
            xneg.removeLast();
            ypos.removeLast();
        }
        while (!yneg.isEmpty() && !xpos.isEmpty()) {
            res -= yneg.getLast() * xpos.getLast();
            yneg.removeLast();
            xpos.removeLast();
        }

        while (!xpos.isEmpty() && !ypos.isEmpty()) {
            res += xpos.getLast() * ypos.getFirst();
            xpos.removeLast();
            ypos.removeFirst();
        }
        while (!xneg.isEmpty() && !yneg.isEmpty()) {
            res += xneg.getLast() * yneg.getFirst();
            xneg.removeLast();
            yneg.removeFirst();
        }



        out.println("Case #"+ c + ": " + res);
    }

    static PrintStream out;
    public static void main(String[] args) throws Throwable {
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream(args[0])));
        out = new PrintStream(new FileOutputStream(args[1]));
        int n = readInt(in);
        for (int i = 0; i < n; i++) {
            process(i + 1, in);
        }
        out.flush();
        out.close();
    }

    private static int readInt(BufferedReader in) {
        try {
            return Integer.parseInt(in.readLine());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

}
