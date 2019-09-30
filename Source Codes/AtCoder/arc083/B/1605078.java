import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    long[][] minD = new long[n][n];
    long[][] ansD = new long[n][n];
    long sum = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        minD[i][j] = sc.nextLong();
        ansD[i][j] = minD[i][j];
      }
    }
    long ans = -1;
    boolean flg = true;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        for(int k = 0; k < n; k++) {
          if((i != j) && (i != k) && (j != k)) {
            if((minD[i][j] > (minD[i][k] + minD[k][j])) || (minD[i][k] > (minD[i][j] + minD[j][k])) || (minD[j][k] > (minD[j][i] + minD[i][k]))) flg = false;
          }
        }
      }
    }
    if(flg) {
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
          for(int k = 0; k < n; k++) {
            if((i != j) && (i != k) && (j != k)) {
              if(minD[i][j] == (minD[i][k] + minD[k][j])) ansD[i][j] = 0;
              if(minD[i][k] == (minD[i][j] + minD[j][k])) ansD[i][k] = 0;
              if(minD[j][k] == (minD[j][i] + minD[i][k])) ansD[j][k] = 0;
            }
          }
        }
      }
      for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
          sum += ansD[i][j];
        }
      }
      ans = sum;      
    }
    System.out.println(ans);
  }
}