import java.util.Scanner;
import java.util.Arrays;
import java.util.Map;
import java.util.HashMap;

public class Main{
  static final long INF = Long.MAX_VALUE / 2;
  static int n;
  static long k;
  static int[] a;

  static final boolean DEBUG = false;

  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    n = sc.nextInt();
    k = sc.nextInt();
    a = new int[n];
    for(int i = 0; i < n; i++){
      a[i] = sc.nextInt();
    }

    long[] b = new long[n + 1];
    for(int i = 1; i <= n; i++){
      b[i] = b[i - 1] + a[i - 1] - k;
    }

    if(DEBUG){
      System.out.println(Arrays.toString(b));
    }

    long sum = 0;
    for(int i = 1; i <= n; i++){
      if(b[i] >= 0){
        ++sum;
      }
    }

    if(DEBUG){
      System.out.println("sum = " + sum);
    }

    long[] c = Arrays.copyOf(b, b.length);

    Arrays.sort(b, 1, n + 1);

    Map< Long, Integer > map = new HashMap< >();
    int count = 1;
    for(int i = 1; i <= n; i++){
      if(b[i - 1] != b[i]){
        ++count;
      }
      map.put(b[i], count);
    }

    for(int i = 1; i <= n; i++){
      b[i] = map.get(c[i]);
    }

    if(DEBUG){
      System.out.println(Arrays.toString(b));
    }

    if(DEBUG){
      for(int i = 1; i <= n; i++){
        assert 0 < b[i];
        assert b[i] <= n;
      }
      System.out.println(Arrays.toString(b));
    }

    long diff = 0;
    BinaryIndexedTree bit = new BinaryIndexedTree(n + 2);
    for(int i = 1; i <= n; i++){
      sum += bit.sum((int)(b[i] + 0));
      if(DEBUG){
        diff += bit.sum((int)(b[i] + 1));
        System.out.println("diff = " + diff);
      }
      bit.add((int)b[i], 1);
      if(DEBUG){
        System.out.println("sum = " + sum);
      }
    }

    if(DEBUG){
      System.out.println("diff = " + diff);
    }

    System.out.println(sum);
  }
}

class BinaryIndexedTree {
  int n;
  long[] bit;

  BinaryIndexedTree(int n){
    this.n = n;
    this.bit = new long[n + 1];
  }

  long sum(int i){
    long s = 0;
    while(i > 0){
      s += bit[i];
      i -= i & -i;
    }
    return s;
  }

  void add(int i, long x){
    while(i <= n){
      bit[i] += x;
      i += i & -i;
    }
  }
}