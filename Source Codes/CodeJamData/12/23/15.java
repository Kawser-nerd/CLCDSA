import java.io.File;
import java.io.FileWriter;
import java.util.BitSet;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;


public class C {
  public static void main(String[]args) throws Exception {
    File f = new File(args[0]);
    File f2 = new File(f.getParentFile(),f.getName()+".out");
    Scanner s = new Scanner(f);
    int T = s.nextInt();
    for (int t = 1; t <= T; t++) {
      int N = s.nextInt();
      long points[] = new long[N];
      for (int i=0;i<N;i++)
        points[i]=s.nextLong();

      println(f2,"Case #"+t+":\n"+solve(points));
    }
    s.close();
  }

  private static String solve(long[] points) {
    TreeMap<Long,BitSet> m = new TreeMap<Long,BitSet>();
    long max = 0;
    for (int i=0;i<points.length;i++) {
      max += points[i];
      BitSet bs = new BitSet();
      bs.set(i);
      m.put(points[i], bs);
    }
    BitSet bsall = new BitSet();
    bsall.set(0, points.length);
    m.put(max, bsall);
    m.put((long)0, new BitSet());
    long key = m.higherKey(0l);
    while (key < max) {
      BitSet bs = m.get(key);
      for (int i=0;i<points.length;i++) {
        if (bs.get(i)) continue;
        long next = key + points[i];
        BitSet nextbs = m.get(next);
        if (nextbs == null) {
          nextbs = (BitSet)bs.clone();
          nextbs.set(i);
          m.put(next, nextbs);
        } else {
          BitSet clone = (BitSet)bs.clone();
          clone.set(i);
          if (!nextbs.intersects(clone)) {
            return s(clone, points) + "\n" + s(nextbs, points);
          } else {
            if (nextbs.equals(clone)) continue;
            BitSet clone2 = (BitSet)clone.clone();
            clone2.andNot(nextbs);
            nextbs.andNot(clone);
            return s(clone2, points) + "\n" + s(nextbs, points);
          }
        }
      }
      key = m.higherKey(key);
    }
    return "Impossible";
    
  }
  static String s(BitSet bs,long[]points) {
    String str = "";
    for (int i = bs.nextSetBit(0); i != -1; i = bs.nextSetBit(i+1)) {
      if (str.length() != 0) str += " ";
      str += points[i];
    }
    return str;
  }

  static void println(File f, String s) throws Exception {
    FileWriter w = new FileWriter(f,true);
    w.write(s+"\n");
    w.close();
    System.out.println(s);
  }
}
/*
 * 177
 * 59 59 1 0 0 0 58
 * 
 * 1 1 1 1 1 5
 * 
 * 10
 * 
 * 3.33333
 * 1 + .2 * 10 = 3
 * (3.333 - 1) * 2 / 10
 * 
 */
