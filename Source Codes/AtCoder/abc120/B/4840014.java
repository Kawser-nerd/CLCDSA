import java.util.*;

class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int k = sc.nextInt();
        int n = 0;
        for (int i =101; i >= 1; i--){
          if(a % i == 0 && b % i == 0){
            n++;
            if(n == k) System.out.println(i);
          }
        }
    }
}