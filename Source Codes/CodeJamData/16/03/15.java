// Author: Alejandro Sotelo Arevalo
package qualification;

import java.io.*;
import java.math.*;
import java.util.*;

public class C_CoinJam {
  // --------------------------------------------------------------------------------
  private static final String FILENAME="data/qualification/C-large";
  private static final boolean STANDARD_OUTPUT=false;
  private static BufferedReader in=null;
  private static PrintStream out=null;
  public static void main(String[] args) throws Throwable {
    try (BufferedReader reader=in=new BufferedReader(new FileReader(FILENAME+".in"))) {
      try (PrintStream writer=out=!STANDARD_OUTPUT?new PrintStream(FILENAME+".out"):System.out) {
        process();
      }
    }
  }
  // --------------------------------------------------------------------------------
  private static void process() throws Throwable {
    for (int caseNumber=1,T=Integer.parseInt(in.readLine()); caseNumber<=T; caseNumber++) {
      StringTokenizer tokenizer=new StringTokenizer(in.readLine());
      int N=Integer.parseInt(tokenizer.nextToken());
      int J=Integer.parseInt(tokenizer.nextToken());
      out.println("Case #"+caseNumber+":");
      solveBig(N,J);
    }
  }
  public static void solveBig(int N, int J) {
    long[] primesL={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    BigInteger[] primes=new BigInteger[primesL.length];
    for (int i=0; i<primes.length; i++) {
      primes[i]=BigInteger.valueOf(primesL[i]);
    }
    int j=0;
    loop: for (BigInteger i=BigInteger.ZERO,t=BigInteger.ONE.shiftLeft(N-2); j<J&&i.compareTo(t)<0; i=i.add(BigInteger.ONE)) {
      BigInteger x=i.shiftLeft(1).or(BigInteger.ONE).or(BigInteger.ONE.shiftLeft(N-1));
      String string=x.toString(2);
      BigInteger witnesses[]=new BigInteger[11];
      witnesses[1]=new BigInteger(string);
      for (int base=2; base<=10; base++) {
        BigInteger n=new BigInteger(string,base);
        for (int k=0; k<primes.length&&primes[k].compareTo(n)<0; k++) {
          if (n.mod(primes[k]).equals(BigInteger.ZERO)) {
            witnesses[base]=primes[k];
            break;
          }
        }
        if (witnesses[base]==null) continue loop;
      }
      print(witnesses);
      j++;
    }
  }
  public static void solveSmall(int N, int J) {
    int j=0;
    loop: for (int i=0,t=(1<<(N-2)); j<J&&i<t; i++) {
      long x=(((long)i)<<1)|1L|(1L<<(N-1));
      String string=Long.toBinaryString(x);
      long witnesses[]=new long[11];
      witnesses[1]=Long.parseLong(string,10);
      for (int base=2; base<=10; base++) {
        long n=Long.parseLong(string,base);
        for (long f=2L; f*f<=n; f++) {
          if (n%f==0) {
            witnesses[base]=f;
            break;
          }
        }
        if (witnesses[base]==0L) continue loop;
      }
      print(witnesses);
      j++;
    }
  }
  private static void print(long[] witnesses) {
    out.print(witnesses[1]);
    for (int base=2; base<=10; base++) {
      out.print(" "+witnesses[base]);
    }
    out.println();
  }
  private static void print(BigInteger[] witnesses) {
    out.print(witnesses[1]);
    for (int base=2; base<=10; base++) {
      out.print(" "+witnesses[base]);
    }
    out.println();
  }
}
