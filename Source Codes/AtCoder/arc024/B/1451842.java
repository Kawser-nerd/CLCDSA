import java.util.*;

public class Main {
  public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);    

      int N = sc.nextInt();
      
      int a[] = new int[N];
      
      for(int i = 0;i < N;i++){
          a[i] = sc.nextInt();
      }
      
      int cnt0 = 0;
      int cnt1 = 0;
      
      for(int i = 0;i < N;i++){          
          if(a[i] == 0){
              cnt0++;
          }          
          if(a[i] == 1){
              cnt1++;
          }          
      }
      
      if(cnt0 == N || cnt1 == N){
          System.out.println(-1);
          return;
      }
      
      int max = 0;      
      cnt0 = 0;
      cnt1 = 0;
         
      for(int i = 0;i < 2*N;i++){
          if(a[i%N] == 0){
                if(cnt1 > 0){
                    max = Math.max(max,cnt1);
                    cnt1 = 0;
                }            
                cnt0++;
          }
          if(a[i%N] == 1){
                if(cnt0 > 0){
                     max = Math.max(max,cnt0);
                     cnt0 = 0;
                }
                cnt1++;                 
          }                          
      }                         
      
      System.out.println((max-1)/2 + 1);
      
  }  
}