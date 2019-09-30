import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    
    String[] s = sc.nextLine().split(" ");
    int R = Integer.parseInt(s[0]);
    int C = Integer.parseInt(s[1]);
    int K = Integer.parseInt(s[2]);
    int[] tate = new int[R];
    int[] yoko = new int[C];
    
    int N = Integer.parseInt(sc.nextLine());
    int[][] candy = new int[N][2];
    for(int i = 0; i < N; i++){
      String[] t = sc.nextLine().split(" ");
      candy[i][0] = Integer.parseInt(t[0]) - 1;
      candy[i][1] = Integer.parseInt(t[1]) - 1;
      
      tate[candy[i][0]]++;
      yoko[candy[i][1]]++;
    }
    
    int[] tate_K = new int[K+1];
    int[] yoko_K = new int[K+1];
    for(int i = 0; i < R; i++){
      if(tate[i] <= K){
	    tate_K[tate[i]]++;
      }
    }
    for(int i = 0; i < C; i++){
      if(yoko[i] <= K){
	    yoko_K[yoko[i]]++;
      }
    }
    
    long count = 0;
    for(int i = 0; i <= K; i++){
      count += (long)(tate_K[i] * yoko_K[K-i]);
    }
    
    for(int i = 0; i < N; i++){
      if(tate[candy[i][0]] + yoko[candy[i][1]] == K){
        count--;
      }else if(tate[candy[i][0]] + yoko[candy[i][1]] == K+1){
        count++;
      }
    }
    System.out.println(count);
  }
}