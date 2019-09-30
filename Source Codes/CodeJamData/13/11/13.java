import java.util.*;
import java.io.*;
import java.math.*;
import static java.lang.Math.*;

public class Main{

  BigInteger sumSq(long i){
    return BigInteger.valueOf(i).multiply(BigInteger.valueOf(i+1)).multiply(BigInteger.valueOf(2*i+1)).divide(BigInteger.valueOf(6));
  }

  // assume i is even
  BigInteger sumEvSq(long i){
    return BigInteger.valueOf(4).multiply(sumSq(i/2));
  }

  // assume i is odd
  BigInteger sumOddSq(long i){
    return sumSq(i).subtract(sumEvSq(i-1));
  }

  BigInteger caseEv(long i){
    return sumEvSq(i).subtract(sumOddSq(i-1));
  }

  BigInteger caseOdd(long i){
    return sumOddSq(i).subtract(sumEvSq(i-1));
  }

  public void go(){
/*
    System.err.printf("sumSq(3) = %s\n", sumSq(3));
    System.err.printf("sumOddSq(5) = %s\n", sumOddSq(5));
*/
    int ttt=sc.nextInt();
    for(int tt=1; tt<=ttt; ++tt){
      long r=sc.nextLong(), t=sc.nextLong();
      long lo=0, hi=(long)1e12;
      while(hi-lo > 1){
        long mid = (lo+hi)/2;
        if(r%2 == 1){
          if(caseEv(r-1+2*mid).subtract(caseEv(r-1)).compareTo(BigInteger.valueOf(t)) <= 0)
            lo = mid;
          else
            hi = mid;
        }else{
          if(caseOdd(r-1+2*mid).subtract(caseOdd(r-1)).compareTo(BigInteger.valueOf(t)) <= 0)
            lo = mid;
          else
            hi = mid;
        }
      }
      System.out.printf("Case #%d: %d\n", tt, lo);
    }
  }

  // generic main stuff
  static Scanner sc;
  // static PrintWriter pw;
  // static long startTime;
  public static void main(String[] args) throws Exception{
    sc = new Scanner(System.in);
    // pw = new PrintWriter(System.out);
    (new Main()).go();
    // pw.flush();
    System.exit(0);
  }

  // syntax
  // ArrayList<Integer>[] myMat = (ArrayList<Integer>[]) new ArrayList[nB];

  // Pairs
  public class ii implements Comparable< ii >{
    int x, y;
    public ii(){}
    public ii(int xx, int yy){ x=xx; y=yy; }
    public int compareTo(ii p){ return x!=p.x ? x-p.x : y-p.y; }
    public int hashCode(){ return 31*x+y; }
    public boolean equals(Object o){
      if(!(o instanceof ii)) return false;
      ii p = (ii) o;
      return x==p.x && y==p.y;
    }
    public String toString(){ return "("+x+", "+y+")"; }
  }
/*
     public class pair< X extends Comparable< X >,Y extends Comparable< Y > > implements Comparable< pair< X,Y > >{
     X x;
     Y y;
     public pair(){}
     public pair(X xx, Y yy){ x=xx; y=yy; }
     public int compareTo(pair< X,Y > p){ return x.compareTo(p.x)!=0 ? x.compareTo(p.x) : y.compareTo(p.y); }
     public int hashCode(){ return 31*x.hashCode()+y.hashCode(); }
     public boolean equals(Object o){
     if((o.getClass() != this.getClass())) return false;
     pair< X,Y > p = (pair< X,Y >) o;
     return x.equals(p.x) && y.equals(p.y);
     }
     public String toString(){ return "("+x+", "+y+")"; }
     }
*/
/*
  // my stuff
  public static final int INF = 1000*1000*1000+7;
  public static final double EPS = 1e-9;
  public static final double PI = 2*acos(0.0);
  public void rev(Object[] a){ for(int i=0; i<a.length/2; ++i){ Object t=a[i]; a[i]=a[a.length-1-i]; a[a.length-1-i]=t; } }
  public void rev(int[] a){ for(int i=0; i<a.length/2; ++i){ int t=a[i]; a[i]=a[a.length-1-i]; a[a.length-1-i]=t; } }
  public int bit_count(long x){ return x==0 ? 0 : 1+bit_count(x&(x-1)); }
  public int low_bit(int x){ return x&-x; } // 0011 0100 returns 0000 0100
  public int sign(int x){ return x<0 ? -1 : x>0 ? 1 : 0; }
  public int sign(double x){ return x<-EPS ? -1 : x>EPS ? 1 : 0; }
  int[] unpack(vi a){
    int[] ret = new int[a.size()];
    for(int i=0; i<a.size(); ++i)
      ret[i] = a.get(i);
    return ret;
  }
*/
/*
  // capable of reading   2.86M 6dp doubles per second
  //                      2.16M 12dp doubles per second
  //                      2.75M int per second
  public class myScanner{
    private BufferedReader f;
    private StringTokenizer st;
    public myScanner(BufferedReader ff){ f=ff; st=new StringTokenizer(""); }
    public int nextInt(){ return Integer.parseInt(nextToken()); }
    public double nextDouble(){ return Double.parseDouble(nextToken()); }
    public String nextLine(){
      st=new StringTokenizer("");
      String ret="";
      try{ ret=f.readLine(); }catch(Exception e){}
      return ret;
    }
    public String nextToken(){
      while(!st.hasMoreTokens()) try{ st=new StringTokenizer(f.readLine()); } catch(Exception e){}
      return st.nextToken();
    }
  }
*/
}
