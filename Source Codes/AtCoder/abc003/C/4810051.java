//AtCoder????????

import java.util.*;

class Main{
  public static int N;
  public static int K;
  public static ArrayList<Integer> ratelist= new ArrayList<Integer>();
  public static double takahashirate= 0;
  public static void main(String[] args) {
    Scanner sc= new Scanner(System.in);
    N= sc.nextInt();
    K= sc.nextInt();
    for (int i= 0; i<N; i++) {
      ratelist.add(sc.nextInt());
    }
    Collections.sort(ratelist);
    List<Integer> sbratelist= ratelist.subList(N-K, N);
    for (int target : sbratelist) {
      takahashirate= (takahashirate+target)/2.0;
    }
    System.out.println(takahashirate);
  }
}