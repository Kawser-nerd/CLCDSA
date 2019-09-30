import java.util.Scanner;
public class Main{

   public static void main(String[] args){
      new Main().solve();
   }

   public void solve(){
      // input data
      long sum = 0;
      long whiteCost = 0;
      long minWhiteCost = 0;
      long blackCost = 0;
      long minBlackCost = 0;
      long tmp = 0;
      Scanner scanner = new Scanner(System.in);
      int N = scanner.nextInt();
      int K = scanner.nextInt();
      long[] a = new long[N];
      for(int i=0; i<a.length; i++){
         a[i] = scanner.nextLong();
         if(a[i] > 0) sum += a[i];
      }
      for(int i=0; i<K; i++){
         if(a[i] > 0) whiteCost += a[i];
         else blackCost += Math.abs(a[i]);
         tmp += a[i];
      }
      minWhiteCost = whiteCost;
      minBlackCost = blackCost;
      if(N-K > 0){
         for(int i=K; i<N; i++){
            if(a[i] > 0) whiteCost += a[i];
            else blackCost += Math.abs(a[i]);
            if(a[i-K] > 0) whiteCost -= a[i-K];
            else blackCost -= Math.abs(a[i-K]);
            minWhiteCost = Math.min(minWhiteCost, whiteCost);
            minBlackCost = Math.min(minBlackCost, blackCost);
         }
         sum -= Math.min(minWhiteCost,minBlackCost);
      }else{
         if(tmp > 0) sum = tmp;
         else sum = 0;
      }
      System.out.println(sum);
   }

}