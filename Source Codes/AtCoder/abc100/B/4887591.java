import java.util.*;

class Main{

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int d = sc.nextInt();
        int N = sc.nextInt();
        int i = 1;
        int result = 0;
        int term = (int)Math.pow(100, d);
      
      while (N != 0){
        result = term * i++;
          int tmp = result;
          int num = 0;
        while( (tmp%100) == 0){
            tmp/=100;
            num++;
          }
        if ( num > d){
          i++;
        }
        N--;
      }
      result = --i * term;
        System.out.println(result);

    }
}