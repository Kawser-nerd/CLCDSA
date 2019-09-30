import java.util.*;

public class C {

  public static void main(String args[]) {
    (new C()).exec();
  }

  void exec() {

    Scanner cin = new Scanner(System.in);

    int t = cin.nextInt();
    for(int z=0; z<t; ++z) {
      int k = cin.nextInt();
      int value[] = new int[k];
      boolean used[] = new boolean[k];
      int count = 0;
      int cur = 0;
      while(count < k) {
        for(int i=0; i<k; ++i) {
          if( used[i] ) { continue; }
          if( cur == count ) {
            value[i] = ++count;
            cur = 0;
            used[i] = true;
          }
          else { ++cur; }
        }
      }
      System.out.print("Case #" + (z + 1) + ":");
      int n = cin.nextInt();
      for(int i=0; i<n; ++i) {
        System.out.print(" " + value[cin.nextInt() - 1]);
      }
      System.out.println();
    }

  }

}
