import java.util.Scanner;
import java.util.Collections;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Queue;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.HashMap;
import java.util.TreeSet;

public class Main {
 	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int C = scanner.nextInt();
    int[][] D = new int[C][C];
    for(int i = 0; i < C; i++){
      for(int j = 0; j < C; j++){
        D[i][j] = scanner.nextInt();
      }
    }
    int[][] c = new int[N][N];
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        c[i][j] = scanner.nextInt()-1;
      }
    }
    int[][] count = new int[C][3];
    for(int x = 0; x < N; x++){
      for(int y = 0; y < N; y++){
        if((x + y) % 3 == 0){
          count[c[x][y]][0] += 1;
        }
        if((x + y) % 3 == 1){
          count[c[x][y]][1] += 1;
        }
        if((x + y) % 3 == 2){
          count[c[x][y]][2] += 1;
        }
      }
    }
    //dp0[i] := (x+y)%3=0??????i??????????????
    int[] dp0 = new int[C];
    int[] dp1 = new int[C];
    int[] dp2 = new int[C];
    for(int k = 0; k < C; k++){
      for(int i = 0; i < C; i++){
        dp0[k] += count[i][0] * D[i][k];
        dp1[k] += count[i][1] * D[i][k];
        dp2[k] += count[i][2] * D[i][k];
      }
    }
    int min = Integer.MAX_VALUE/2;
    for(int i = 0; i < C; i++){
      for(int j = 0; j < C; j++){
        for(int k = 0; k < C; k++){
          if(i != j && j != k && k != i){
            min = Math.min(min, dp0[i]+dp1[j]+dp2[k]);
          }
        }
      }
    }
    System.out.println(min);
  }
  public static int upperBound(long[] a,long val){
    return upperBound(a,0,a.length,val);
  }
  public static int upperBound(long[] a,int l,int r,long val){
    if(r-l==1){
      if(a[l]>val) return l;
      return r;
    }
    int mid=(l+r)/2;
    if(a[mid]>val){
      return upperBound(a,l,mid,val);
    }else{
      return upperBound(a,mid,r,val);
    }
  }
  public static int lowerBound(long[] a,long val){
     return lowerBound(a,0,a.length,val);
 }
  public static int lowerBound(long[] a,int l,int r,long val){
    if(r-l==1){
      if(a[l]<val) return r;
      return l;
    }
    int mid=(l+r)/2;
    if(a[mid]<val){
      return lowerBound(a,mid,r,val);
    }else{
      return lowerBound(a,l,mid,val);
    }
  }
}