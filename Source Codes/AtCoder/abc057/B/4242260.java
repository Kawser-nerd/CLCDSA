import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    long[][] stu = new long[N][2];
    long[][] poi = new long[M][2];
    for(int i = 0; i < N; i++){
      stu[i][0] = sc.nextLong();
      stu[i][1] = sc.nextLong();
    }
    for(int i = 0; i < M; i++){
      poi[i][0] = sc.nextLong();
      poi[i][1] = sc.nextLong();
    }
    for(int i = 0; i < N; i++){
      int minIndex = -1;
      long minDis = Long.MAX_VALUE;
      for(int j = 0; j < M; j++){
        long tmpDis = Math.abs(stu[i][0]-poi[j][0]) + Math.abs(stu[i][1]-poi[j][1]);
        if(minDis > tmpDis){
          minDis = tmpDis;
          minIndex = j+1;
        }
      }
      System.out.println(minIndex);
    }
  }
}