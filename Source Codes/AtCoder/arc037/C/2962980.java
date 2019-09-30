import java.util.*;
class Main{
  static long[] a,b;
  static int n;
  static long count(long v){
    long res =0;
    for(int i=0;i<n;++i){
      int l = -1, r=n;
      while(r-l>1){
        int c = (l+r)/2;
        if(a[i]*b[c]<=v)l=c;
        else r=c;
    }
      res += r;
    }
    return res;
  }
  
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();
    long k = sc.nextLong();
    a = new long[n];
    b = new long[n];
    for(int i=0;i<n;++i)a[i]=sc.nextLong();
    for(int i=0;i<n;++i)b[i]=sc.nextLong();
    Arrays.sort(a);Arrays.sort(b);
    long l = 0, r = Long.MAX_VALUE/2;
    while(r-l>1L){
      long c = (l+r)/2;
     // System.out.println(count(c));
      if(count(c)<k)l=c;
      else r=c;
    }
    System.out.println(r);
  }
}