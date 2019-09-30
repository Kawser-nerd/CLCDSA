import java.util.*;

public class A {

  public static void main(String args[]) {
    (new A()).exec();
  }

  void exec() {

    Scanner cin = new Scanner(System.in);

    int n = cin.nextInt();
    for(int z=0; z<n; ++z) {
      int m = cin.nextInt();
      int ms[] = new int[m];
      int me[] = new int[m];
      boolean bf[] = new boolean[m];
      for(int i=0; i<m; ++i) {
        ms[i] = cin.nextInt();
        me[i] = cin.nextInt();
        bf[i] = cin.next().equals("BIRD");
        if( !bf[i] ) { cin.next(); }
      }
      int as = Integer.MAX_VALUE;
      int bs = 0;
      int ae = Integer.MAX_VALUE;
      int be = 0;
      boolean none = true;
      for(int i=0; i<m; ++i) {
        if( bf[i] ) {
          as = Math.min(as, ms[i]);
          bs = Math.max(bs, ms[i]);
          ae = Math.min(ae, me[i]);
          be = Math.max(be, me[i]);
          none = false;
        }
      }
      System.out.println("Case #" + (z + 1) + ":");
      int c = cin.nextInt();
      int cs[] = new int[c];
      int ce[] = new int[c];
    MAIN:
      for(int i=0; i<c; ++i) {
        cs[i] = cin.nextInt();
        ce[i] = cin.nextInt();
        if( as <= cs[i] && cs[i] <= bs && ae <= ce[i] && ce[i] <= be ) {
          System.out.println("BIRD");
          continue MAIN;
        }
        for(int j=0; j<m; ++j) {
          if( bf[j] ) { continue; }
          if( as <= ms[j] && ms[j] <= bs ) {
            if( ce[i] <= me[j] && me[j] < ae) {
              System.out.println("NOT BIRD");
              continue MAIN;
            }
            if( be < me[j] && me[j] <= ce[i] ) {
              System.out.println("NOT BIRD");
              continue MAIN;
            }
          }
          else if( ae <= me[j] && me[j] <= be ) {
            if( cs[i] <= ms[j] && ms[j] < as ) {
              System.out.println("NOT BIRD");
              continue MAIN;
            }
            if( bs < ms[j] && ms[j] <= cs[i] ) {
              System.out.println("NOT BIRD");
              continue MAIN;
            }
          }
          else {
            if( none ) {
              if( ce[i] == me[j] && cs[i] == ms[j] ) {
                System.out.println("NOT BIRD");
                continue MAIN;
              }
            }
            else {
              int fail = 0;
              if( ce[i] <= me[j] && me[j] < ae) {
                ++fail;
              }
              else if( be < me[j] && me[j] <= ce[i] ) {
                ++fail;
              }
              if( cs[i] <= ms[j] && ms[j] < as ) {
                ++fail;
              }
              else if( bs < ms[j] && ms[j] <= cs[i] ) {
                ++fail;
              }
              if( fail == 2 ) {
                System.out.println("NOT BIRD");
                continue MAIN;
              }
            }
          }
        }
        System.out.println("UNKNOWN");
      }
    }

  }

}
