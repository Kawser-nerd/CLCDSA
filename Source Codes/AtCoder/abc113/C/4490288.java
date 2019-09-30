import java.util.*;

public class Main {

  static Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {

    int N = sc.nextInt();
    int M = sc.nextInt();

    ArrayList<City> cities = new ArrayList();
    for (int i=0; i<M; i++) {
      cities.add(new City(i, sc.nextInt(), sc.nextInt()));
    }

    cities.sort((x, y) -> {
      if (x.p == y.p) {
        return x.y - y.y;
      } else {
        return x.p - y.p;
      }
    });

    String[] ids = new String[M];

    int count = 0;
    for (int i=0; i<M; i++) {
      City c = cities.get(i);
      if (i == 0 || c.p != cities.get(i-1).p) count = 0;
      else count++;
      ids[c.i] = padding0(c.p, 6) + padding0(count+1, 6);
    }

    for (int i=0; i<M; i++) {
      System.out.println(ids[i]);
    }

  }

  static String padding0(int n, int m) {
    String s = Integer.toString(n);
    while (m - s.length() > 0) s = "0" + s;
    return s;
  }


  static class City {
    int i, p, y;
    City (int i, int p, int y) {
      this.i = i;
      this.p = p;
      this.y = y;
    }
  }

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.