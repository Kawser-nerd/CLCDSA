import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

   public StringBuffer s;
   public boolean ok;
   public String ans;

   public void rec() {
     if (ok) return;

     int pos = -1;
     for (int i = 0; i < s.length(); i++)
       if (s.charAt(i) == '?') {
         pos = i;
         break;
       }

     if (pos == -1) {
       BigInteger b = BigInteger.ZERO;
       for (int i = 0; i < s.length(); i++)
         if (s.charAt(i) == '1')
           b = b.add(BigInteger.ONE.shiftLeft(s.length() - 1 - i));

       BigInteger l = BigInteger.ONE, r = BigInteger.TEN.pow(25);
       while (l.compareTo(r) != 0) {
         BigInteger x = l.add(r).shiftRight(1);
         BigInteger xx = x.multiply(x);
         if (xx.compareTo(b) >= 0)
           r = x;
         else
           l = x.add(BigInteger.ONE);
       }

       BigInteger test = l.multiply(l);
       if (test.compareTo(b) == 0) {
         ok = true;
         ans = test.toString(2);
       }

     } else {
       s.setCharAt(pos, '0');
       rec();
       s.setCharAt(pos, '1');
       rec();
       s.setCharAt(pos, '?');
     }

   }


   public void run() throws IOException {
     Scanner in = new Scanner(new File("D.in"));
     //PrintWriter out = new PrintWriter(System.out);
     PrintWriter out = new PrintWriter(new File("D.out"));

     int T = in.nextInt();
     in.nextLine();
     for (int t = 1; t <= T; t++) {
       out.print("Case #" + t + ": ");

       String ss = in.nextLine();
       s = new StringBuffer(ss);

       ok = false;
       rec();
       out.println(ans);
       out.flush();
     }
     
   }

   public static void main(String[] args) throws IOException {
      new Main().run();
   }
}