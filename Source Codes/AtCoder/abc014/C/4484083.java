import java.util.*;

public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int[] paints = new int[1000001];
    int max = 0;
    int nmax = 0;
    int nmin = 1000000;
    
    for(int i = 0; i < N; i++){
      int a = sc.nextInt();
      int b = sc.nextInt();
      paints[a]++;
      if(b+1 < 1000001){
	    paints[b+1]--;
      }
      
      if(a < nmin){
        nmin = a;
      }
      if(b > nmax){
        nmax = b;
      }
    }
    
    int count = 0;
    for(int i = nmin; i <= nmax; i++){
      count += paints[i];
      if(count == N){
        max = count;
        break;
      }else if(count > max){
        max = count;
      }
    }
    System.out.println(max);
  }
}