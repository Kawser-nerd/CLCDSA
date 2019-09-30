
import java.io.*;
import java.util.*;

class Solver {

    boolean isInFile, isOutFile;
    Scanner reader;
    DataOutputStream writer;
    List<Long> matchList;

    public Solver(String[] args) throws Exception {
        isInFile = (args.length > 0);
        if (isInFile)
            reader = new Scanner(new File(args[0]));
        else
            reader = new Scanner(System.in);
        isOutFile = (args.length > 1);
        if (isOutFile)
            writer = new DataOutputStream(new FileOutputStream(new File(args[1])));

    }

    public void write(String str) throws Exception {
        if (isOutFile)
            writer.writeBytes(str);
        //System.out.print(str);
    }

    public void writeln(String str) throws Exception {
        write(str + System.lineSeparator());
    }

    public static void main(String[] args) throws Exception {
        new Solver(args).solve();
    }

    public void solve() throws Exception {
        init();
        int T = reader.nextInt();
        for (int i = 1; i <= T; i++) {
            write("Case #" + i + ": ");
            solveOne();
            writeln("");
        }
    }

    public String reverse(String str) {
        return new StringBuffer(str).reverse().toString();
    }

    public boolean isPalin(long num) throws Exception {
        String str = Long.toString(num);
        return str.equals(reverse(str));
    }

    public boolean isLong(double d) {
        return (d == (long) d);
    }

    public double sqrt(long num) throws Exception {
        return Math.sqrt(num);
    }

    public void init() throws Exception {
        matchList = new LinkedList<Long>();
        for (int i = 1; i < 10000000; i++) {
            String iStr = Integer.toString(i);

            String pattern1 = iStr + reverse(iStr);
            long long1 = Long.parseLong(pattern1);
            double sqrt1 = sqrt(long1);
            long longSqrt1 = (long) sqrt1;
            if (isLong(sqrt1) && isPalin(longSqrt1))
                matchList.add(long1);

            String pattern2 = iStr + reverse(iStr).substring(1);
            long long2 = Long.parseLong(pattern2);
            double sqrt2 = sqrt(long2);
            long longSqrt2 = (long) sqrt2;
            if (isLong(sqrt2) && isPalin(longSqrt2))
                matchList.add(long2);
        }
        Collections.sort(matchList);
    }

    public void solveOne() throws Exception {
        /* read data */
        long a = reader.nextLong();
        long b = reader.nextLong();
        reader.nextLine();

        /* solve */
        int total = 0;
        for (long l : matchList) {
            if (l >= a && l <= b)
                total++;
        }
        write(Long.toString(total));
    }
}