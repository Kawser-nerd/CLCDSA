import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;

public class Main{
  static int n, m;
  static int[] a;

  static final boolean DEBUG = false;

  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    n = sc.nextInt();
    m = sc.nextInt();
    a = new int[n];
    for(int i = 0; i < n; i++){
      a[i] = sc.nextInt();
    }

    Map< Integer, Set< Integer > > map = new HashMap< >();
    for(int i = 0; i  + 1 < n; i++){
      if(map.containsKey(a[i + 1])){
        map.get(a[i + 1]).add(i);
      }
      else{
        Set< Integer > set = new HashSet< >();
        set.add(i);
        map.put(a[i + 1], set);
      }
    }

    int[] count = new int[m + 1];
    for(int i = 0; i + 1 < n; i++){
      if(a[i] < a[i + 1]){
        count[a[i] + 1]++;
        count[a[i + 1]]--;
      }
      else{
        if(a[i + 1] >= 2){
          count[1]++;
          count[a[i + 1]]--;
        }
        if(a[i] + 1 <= m){
          count[a[i] + 1]++;
          count[m]--;
        }
      }
    }

    int t = 0;
    for(int i = 1; i <= m; i++){
      count[i] += count[i - 1];
      if(DEBUG){
        System.out.println("count[" + i + "] = " + count[i]);
      }
    }

    long sum = 0;
    for(int i = 0; i + 1 < n; i++){
      sum += (long)(a[i + 1] + m - a[i]) % m;
    }

    if(DEBUG){
      System.out.println("sum = " + sum);
    }

    long s = 0;
    for(int i = 0; i + 1 < n; i++){
      if(a[i] > a[i + 1] && 1 <= a[i + 1]){
        s += (long)(1 + (a[i + 1] + m - 1) % m);
      }
      else{
        s += (long)((a[i + 1] + m - a[i]) % m);
      }
    }

    if(DEBUG){
      System.out.println("s1 = " + s);
    }

    sum = Math.min(sum, s);
    for(int x = 2; x <= m; x++){
      if(map.containsKey(x - 1)){
        for(int i : map.get(x - 1)){
          s += (long)((a[i + 1] + m - a[i]) % m - 1);
        }
      }
      s -= (long)count[x - 1];
      if(DEBUG){
        System.out.println("s = " + s);
      }
      sum = Math.min(sum, s);
    }

    if(sum < 0){
      throw new Error();
    }

    System.out.println(sum);
  }
}