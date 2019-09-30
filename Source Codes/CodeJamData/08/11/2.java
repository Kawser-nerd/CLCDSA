import java.util.*;
public class MinimumScalarProduct {
  public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);
    for (int c=0,T=sc.nextInt(); c<T; c++) {
      int n=sc.nextInt();
      long a1[]=new long[n],a2[]=new long[n];
      for (int i=0; i<n; i++) a1[i]=sc.nextLong();
      for (int i=0; i<n; i++) a2[i]=sc.nextLong();
      Arrays.sort(a1);
      Arrays.sort(a2);
      long res=0;
      for (int i=0; i<n; i++) res+=a1[i]*a2[n-1-i];
      System.out.println("Case #"+(c+1)+": "+res);
    }
  }
}
