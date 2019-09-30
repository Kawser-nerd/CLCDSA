//5,236067977499789696409173668731276235440618359611525724270897245410520925637804899414414408378782274969508176150773783504253267724447073863586360121533452708866778173191879165811276645322639856580535761
// VERSION 1: Version that uses the library Apfloat (http://www.apfloat.org/) to manage better precision and special operations.
// Author: Alejandro Sotelo Arévalo
// Java JDK 6.0 + Apfloat Library (http://www.apfloat.org/apfloat_java/lib/apfloat.jar)
// Compile (Linux)  : javac -encoding ISO-8859-1 -cp .:./apfloat.jar Numbers.java
// Compile (Windows): javac -encoding ISO-8859-1 -cp .;./apfloat.jar Numbers.java
// Execute (Linux)  : java -Xmx900M -Xms900M -cp .:./apfloat.jar Numbers
// Execute (Windows): java -Xmx900M -Xms900M -cp .;./apfloat.jar Numbers

import org.apfloat.*;
import java.util.*;
import java.math.*;
public class Numbers {
/*
  static int dec=200000;
  static Apfloat base=ApfloatMath.sqrt(new Apfloat(5,dec)).add(new Apfloat(3,dec));
  static Apfloat foo(long p) {
    if (p==0) return new Apfloat(1,dec);
    if (p==1) return base;
    Apfloat num=foo(p>>1); num=ApfloatMath.pow(num,2);
    if ((p&1L)==1L) num=num.multiply(base);
    return num;
  }
*/
/*
    for (int i=10000; i<10100; i++) {
      String s=foo(i).toString(true);
      int pp=s.indexOf('.');
      if (pp!=-1) s=s.substring(Math.max(0,pp-3),pp);
      if (!s.equals(jojojofunction(i))) System.out.println("err-------"+i);
      if (i%1==0) System.out.println(i);
    }
*/
  static int[] jojojo={
143,
751,
935,
607,
903,
991,
335,
47,
943,
471,
55,
447,
463,
991,
95,
607,
263,
151,
855,
527,
743,
351,
135,
407,
903,
791,
135,
647,
343,
471,
455,
847,
263,
191,
95,
807,
463,
551,
455,
527,
343,
951,
335,
207,
903,
591,
935,
247,
743,
471,
855,
247,
63,
391,
95,
7,
663,
951,
55,
527,
943,
551,
535,
7,
903,
391,
735,
847,
143,
471,
255,
647,
863,
591,
95,
207,
863,
351,
655,
527,
543,
151,
735,
807,
903,
191,
535,
447,
543,
471,
655,
47,
663,
791,
95,
407,
63,
751,
255,
527
};
  static String jojojofunction(long l) {
    if (l==0) return "001";
    if (l==1) return "005";
    if (l==2) return "027";
    String s=""+jojojo[(int)((l-3)%jojojo.length)];
    while (s.length()<3) s="0"+s;
    return s;
  }
  public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);
    for (int c=0,T=sc.nextInt(); c<T; c++) {
      System.out.println("Case #"+(c+1)+": "+jojojofunction(sc.nextLong()));
    }
  }
}

