/**
 * @author Finn Lidbetter
 */
import java.util.*;
import java.io.*;
import java.awt.geom.*;

public class Main {
  static long[] t;
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();

    String[] s = br.readLine().split(" ");
    int n = Integer.parseInt(s[0]);
    long k = Long.parseLong(s[1]);
    long[] arr = new long[n];
    Pair[] pairs = new Pair[n+1];
    long arrSum = 0;
    for (int i=0; i<n; i++) {
      arr[i] = Long.parseLong(br.readLine());
      arrSum += arr[i];
      pairs[i] = new Pair(i, arrSum-((long)(i+1))*k);
    }
    pairs[n] = new Pair(-1,0);
    Arrays.sort(pairs);

    //System.out.println(Arrays.toString(pairs));
    FT1 ft = new FT1(n+1);
    long sum = 0;
    for (int i=0; i<n+1; i++) {
      Pair p = pairs[i];
      ft.add(p.index+2, 1);
      long prev = sum;
      sum += ft.sum(1,p.index+1);
      //System.out.println(ft.print());
      //System.out.println("Added: "+(sum-prev)+" on insert of: "+p);
    }
    System.out.println(sum);

  }
}
class Pair implements Comparable<Pair> {
  int index;
  long val;
  Pair(int i, long v) {
    index = i;
    val = v;
  }
  public int compareTo(Pair p2) {
    if (val==p2.val)
      return index-p2.index;
    return (val-p2.val) > 0 ? 1 : -1;
  }
  public String toString() {
    return "["+val+","+index+"]";
  }
}
class FT1 {
  int[] arr;
  FT1(int n) {
    arr = new int[n+1];
  }
  int sum(int i, int j) {
    return sum(j)-sum(i-1);
  }
  int sum(int i) {
    int sum=0;
    while (i>0) {
      sum+=arr[i];
      i-=i&-i;
    }
    return sum;
  }
  void add(int i, int delta) {
    if (i<=0)
      return;
    while(i<arr.length) {
      arr[i] += delta;
      i+=i&-i;
    }
  }
  String print() {
    String[] s = new String[arr.length-1];
    for (int i=0; i<s.length; i++) {
      s[i] = ""+ sum(i+1,i+1);
    }
    return String.join(", ",s);
  }
}