import java.util.*;

public class C {

  private class Hiker implements Comparable<Hiker> {
    
    long nextCompletion;
    long timeForLap;
    int lap;
    
    Hiker(long nextCompletion, long timeForLap, int lap) {
      this.nextCompletion = nextCompletion;
      this.timeForLap = timeForLap;
      this.lap = lap;
    }
  
    @Override
    public int compareTo(Hiker that) {
      if(this.nextCompletion < that.nextCompletion) {
        return -1;
      } else if (this.nextCompletion > that.nextCompletion) {
        return 1;
      } else {
        return that.lap - this.lap;
      }
    }
  }

  String solve(Scanner sc) {
    PriorityQueue<Hiker> pq = new PriorityQueue<Hiker>();
  
    int N = sc.nextInt();
    for(int i = 0; i < N; i++) {
      int D = sc.nextInt();
      int H = sc.nextInt();
      long M = sc.nextLong();
      
      for(int j = 0; j < H; j++) {
        long timeForLap = M + j;
        pq.add(new Hiker((360-D)*timeForLap, timeForLap, 0));
      }
    }
    
    int s = pq.size();
    int limit = s * 2;
    int min = s;
    for(int i = 0; i < 10 * limit; i++) {
      Hiker h = pq.poll();
      if(h.lap == 0) {
        s--;
      } else {
        s++;
      }
      
      min = Math.min(min, s);
      pq.add(new Hiker(h.nextCompletion + 360 * h.timeForLap, h.timeForLap, h.lap + 1));
    }
    
    return "" + min;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    
    int T = sc.nextInt();
    for(int cs = 1; cs <= T; cs++) {
      String res = new C().solve(sc);
      System.out.println("Case #" + cs + ": " + res);
    }
    
    sc.close();
  }
  
}
