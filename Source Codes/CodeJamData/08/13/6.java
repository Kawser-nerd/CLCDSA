import java.math.*;
import java.util.*;

public class z {


  static BigDecimal sqrt (BigDecimal z) {
    BigDecimal l = BigDecimal.valueOf (2);
    BigDecimal r = BigDecimal.valueOf (3);
    for (int i = 0; i < 100; i++) {
      BigDecimal x = l.add (r).divide (BigDecimal.valueOf (2));
      if (x.multiply (x).compareTo (z) >= 0) r = x; else l = x;
    };
    return l.add (r).divide (BigDecimal.valueOf (2));
  };


  public static void main (String args[]) {
    BigDecimal t1 = BigDecimal.valueOf (3);
    BigDecimal t2 = t1.add (sqrt (BigDecimal.valueOf (5)));
    //System.out.println (t2);

    String s [] = new String [31];

    BigDecimal p = t2;

    for (int i = 1; i <= 30; i++) {
      String q = "" + p;
      int h = q.indexOf ('.');
      int b = Math.max (h - 3, 0);
      //System.out.println (q + " " + h + " " + b);
      q = q.substring (b, h);
      while (q.length () < 3) q = "0" + q; 
      //System.out.println (q);
      s[i] = q;
      p = p.multiply (t2);
    };

    Scanner in = new Scanner (System.in);
    int t = in.nextInt ();
    for (int i = 1; i <= t; i++) {
      int h = in.nextInt ();
      System.out.println ("Case #" + i + ": " + s[h]);
    };
  };
};
