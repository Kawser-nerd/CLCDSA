import java.util.*;

public class Main
{
  boolean matches ( char a, char b ) {
    if ( a == '?' || b == '?' ) return true;
    return a == b;
  }
  
  long fill ( char s[], int c ) {
    long ans = 0;
    for ( int i = 0; i < s.length; ++i ) {
      ans = ans*10;
      if ( s[i] == '?' ) ans += c;
      else ans += (s[i]-'0');
    }
    return ans;
  }
  
  void solve() {
    Scanner in = new Scanner(System.in);
    int ntc = in.nextInt();
    for ( int test = 1; test <= ntc; ++test ) {
      char a[] = in.next().toCharArray();
      char b[] = in.next().toCharArray();
      int n = a.length;
      
      
      List<Long> listA = new ArrayList<Long>();
      List<Long> listB = new ArrayList<Long>();
      
      for ( int i = 0; i < n; ++i ) {
        char oldA = a[i], oldB = b[i];
        for ( int d = 0; d < 10; ++d ) {
          if ( a[i] == '?' ) a[i] = (char)('0' + (char)d);
          if ( b[i] == '?' ) b[i] = (char)('0' + (char)d);
          for ( int d2 = 0; d2 < 10; ++d2 ) {
            listA.add ( fill(a,d2) );
            listB.add ( fill(b,d2) );
          }
          a[i] = oldA;
          b[i] = oldB;
        }
        if ( a[i] == '?' && b[i] == '?' ) a[i] = b[i] = '0';
        else if ( a[i] == '?' ) a[i] = b[i];
        else if ( b[i] == '?' ) b[i] = a[i];
      }
      
      Collections.sort(listA);
      Collections.sort(listB);
      long bestA = Long.MAX_VALUE, bestB = 0;
      for ( long i : listA )
        for ( long j : listB )
          if ( Math.abs(i-j) < Math.abs(bestA-bestB) ) {
            bestA = i;
            bestB = j;
          }

      String ansA = "" + bestA;
      String ansB = "" + bestB;
      while ( ansA.length() < n ) ansA = "0" + ansA;
      while ( ansB.length() < n ) ansB = "0" + ansB;
      System.out.println ( "Case #" + test + ": " + ansA + " " + ansB );
    }
  }


  public static void main ( String args[] ) {
    new Main().solve();
  }
}
