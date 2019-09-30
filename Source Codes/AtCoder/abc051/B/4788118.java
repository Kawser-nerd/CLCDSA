import java.util.*;
 
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int K = Integer.parseInt(sc.next());
        int S = Integer.parseInt(sc.next());
        int C = 0;

        int nam = 0;

      
      for(int a=0;a<=K;a++){
       for(int b=0;b<=K;b++){
         C = S-a-b;
         if(0<=C&&C<=K){
           nam = nam +1;
         }
       }
      }
      System.out.print(nam);
    }
}