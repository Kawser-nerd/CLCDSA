import java.util.*;

public class Main {
  public static void main(String[] args) throws Exception {
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    boolean[] row = new boolean[N];
    String s = scanner.next();
    for(int i=0;i<N;i++) {
       char n = s.charAt(i);
       if(n == 'E') row[i] = true;
       else row[i] = false;
    }

    int[] countWest = new int[N];
    int count = 0;
    for(int i=0;i<N;i++) {
      countWest[i] = count;
      if(!row[i]) count++;
    }
    int[] countEast = new int[N];
    count = 0;
    for(int i=N-1;i>=0;i--) {
      countEast[i] = count;
      if(row[i]) count++;
    }

    int min = Integer.MAX_VALUE;
    for(int i=0;i<N;i++) {
      int val = countWest[i] + countEast[i];
      if(min > val) min = val;
    }
    System.out.println(min);

    scanner.close();
  }
}