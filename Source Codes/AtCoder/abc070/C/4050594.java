import java.util.Scanner;

public class Main{
  static long[] time;

  public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int N = sc.nextInt();
      time = new long[N];
      for(int i=0;i<N;i++){
        time[i] = sc.nextLong();
      }
      for(int i=0;i<N-1;i++){
        time[i+1] = (time[i])/GCD(time[i],time[i+1])*time[i+1];
        //System.out.println(GCD(time[i],time[i+1]));
      }
      System.out.println(time[N-1]);
  }

  static long GCD(long a,long b){
    if(a<b){
      return GCD(b,a);
    }
    else{
    if(a%b==0){
      return b;
    }
    else{
      return GCD(b,a%b);
    }
  }
 }

}