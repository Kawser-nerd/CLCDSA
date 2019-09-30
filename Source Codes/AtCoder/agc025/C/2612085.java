/**
 * @author Finn Lidbetter
 */
import java.util.*;
import java.io.*;
import java.awt.geom.*;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();

    int n = Integer.parseInt(br.readLine());
    Interval[] intervals = new Interval[n];
    PriorityQueue<Interval> lMax = new PriorityQueue<>(new LMaxComparator());
    PriorityQueue<Interval> rMin = new PriorityQueue<>(new RMinComparator());
    int leftCount = 0;
    int rightCount = 0;
    for (int i=0; i<n; i++) {
      String[] s = br.readLine().split(" ");
      int l = Integer.parseInt(s[0]);
      int r = Integer.parseInt(s[1]);
      intervals[i] = new Interval(l,r,i);
      lMax.offer(intervals[i]);
      rMin.offer(intervals[i]);
      if (r<0) {
        leftCount++;
      } else if (l>0) {
        rightCount++;
      }
    }
    boolean[] vis = new boolean[n];
    //boolean right = Math.abs(lMax.peek().l)>Math.abs(rMin.peek().r);
    boolean right = rightCount>leftCount;
    long sum = 0;
    long pos = 0;
    for (int i=0; i<n; i++) {
      if (right) {
        Interval curr = lMax.poll();
        while (vis[curr.id]) {
          curr = lMax.poll();
        }
        //System.out.println(curr.toString());
        vis[curr.id] = true;
        if (curr.l<=pos && pos<=curr.r) {
          sum += 0;
        } else {
          if (curr.l>pos) {
            sum += curr.l-pos;
            pos = curr.l;
          } else {
            sum += pos-curr.r;
            pos = curr.r;
          }
        }
      } else {
        Interval curr = rMin.poll();
        while (vis[curr.id]) {
          curr = rMin.poll();
        }
        //System.out.println(curr.toString());
        vis[curr.id] = true;
        if (curr.l<=pos && pos<=curr.r) {
          sum += 0;
        } else {
          if (curr.l>pos) {
            sum += curr.l-pos;
            pos = curr.l;
          } else {
            sum += pos-curr.r;
            pos = curr.r;
          }
        }
      }
      right = !right;
    }
    sum += Math.abs(pos);
    System.out.println(sum);
  }
}
class LMaxComparator implements Comparator<Interval> {
  public int compare(Interval i1, Interval i2) {
    return i2.l-i1.l;
  }
}
class RMinComparator implements Comparator<Interval> {
  public int compare(Interval i1, Interval i2) {
    return i1.r-i2.r;
  }
}
class Interval {
  int id;
  int l,r;
  public Interval(int ll, int rr, int idd) {
    id = idd;
    l = ll;
    r = rr;
  }
  public String toString() {
    return String.format("[%d,%d]",l,r);
  }
}