import java.util.*;

public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt(), N1 = sc.nextInt(), N2 = sc.nextInt(), N3 = sc.nextInt();
    if(N == N1 || N == N2 || N == N3){
      System.out.println("NO");
      return;
    }
    
    int count = 0;
    while(N > 0){
      count++;
      if(count > 100){
        System.out.println("NO");
        return;
      }
      
      if(N-3 != N1 && N-3 != N2 && N-3 != N3){
        N-=3;
        continue;
      }else if(N-2 != N1 && N-2 != N2  && N-2 != N3){
        N-=2;
        continue;
      }else if(N-1 != N1 && N-1 != N2 && N-1 != N3){
        N-=1;
        continue;
      }else{
        System.out.println("NO");
        return;
      }
    }
    System.out.println("YES");
  }
}