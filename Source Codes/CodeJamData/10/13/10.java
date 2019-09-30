// Basado en mi solución para http://acm.uva.es/p/v103/10368.html (Euclid's Game)
import java.io.*;
public class C_NumberGame {
  public static void main(String[] args) throws Exception {
    System.setIn(new FileInputStream("test/C-large.in"));
    System.setOut(new PrintStream("test/C-large.out","ISO-8859-1"));
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    for (int c=0,T=Integer.parseInt(br.readLine()); c<T; c++) {
      String w[]=br.readLine().trim().split(" +");
      long A1=Long.parseLong(w[0]);
      long A2=Long.parseLong(w[1]);
      long B1=Long.parseLong(w[2]);
      long B2=Long.parseLong(w[3]);
      long r=A1>A2||B1>B2?0:cuantas1(A1,A2,B1,B2);
      System.out.print("Case #"+(c+1)+": "+r+"\r\n");
    }
    /*
    long D=30;
    for (long A1=1; A1<=D; A1++) for (long A2=A1; A2<=D; A2++) {
      for (long B1=1; B1<=D; B1++) for (long B2=B1; B2<=D; B2++) {
        long c1=cuantas1(A1,A2,B1,B2),c2=cuantas2(A1,A2,B1,B2);
        if (c1!=c2) System.out.println(A1+";"+A2+";"+B1+";"+B2+" : : : "+c1+" vs "+c2);
      }
    }
    */
  }
  static long cuantas1(long A1, long A2, long B1, long B2) {
    long r=0;
    for (long A=A1; A<=A2; A++) {
      long X=(long)Math.ceil((Math.sqrt(5)-1)*A/2),X1=X,X2=X+A-1;
      //if (A>=B1&&A<=B2&&A>=X1&&A<=X2) r++;
      if (X1>B1) r+=Math.min(B2-B1+1,X1-B1);
      if (X2<B2) r+=Math.min(B2-B1+1,B2-X2);
    }
    return r;
  }
  static boolean gana(long a, long b) {
    long x=(long)Math.ceil((Math.sqrt(5)-1)*a/2);
    return b<x||b>=x+a||b==a;
  }
  static long cuantas2(long A1, long A2, long B1, long B2) {
    long r=0;
    for (long A=A1; A<=A2; A++) for (long B=B1; B<=B2; B++) if (gana(A,B)) r++;
    return r;
  }
}
/*  
*/