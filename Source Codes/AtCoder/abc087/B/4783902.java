import java.util.*;
 
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int sam = sc.nextInt();
        int total;int count = 0;
      
      for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
          for(int k=0;k<=c;k++){
            total = i*500+j*100+k*50;
            if(total==sam){count++;}
          }
        }
      }

      System.out.print(count);
    }
}