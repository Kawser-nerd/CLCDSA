import java.io.*;
import java.util.*;

public class a {
  public static void main(String[] args) throws Throwable {
    Scanner s = new Scanner(new BufferedReader(new FileReader("a.in")));
    PrintStream p = new PrintStream(new FileOutputStream("a.out"));
    
    int N = s.nextInt();
    for (int i = 1; i <= N; i++) {
      int d = s.nextInt();
      ArrayList<Integer> v1 = new ArrayList<Integer>();
      ArrayList<Integer> v2 = new ArrayList<Integer>();
      for (int j = 0; j < d; j++) {
        v1.add(s.nextInt());
      }
      for (int j = 0; j < d; j++) {
        v2.add(s.nextInt());
      }
      
      Integer[] u = v1.toArray(new Integer[0]);
      Integer[] v = v2.toArray(new Integer[0]);
      
      Arrays.sort(u);
      Arrays.sort(v, new Comparator<Integer>() {
        public int compare(Integer a, Integer b) {
          return -(a.compareTo(b));
        }
      });
      
      int res = 0;
      for (int j = 0; j < u.length; j++) {
        res += u[j].intValue() * v[j].intValue();
      }
      
      p.println("Case #" + i + ": " + res);
    }
  }
}

