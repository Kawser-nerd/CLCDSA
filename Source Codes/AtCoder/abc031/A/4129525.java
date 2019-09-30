import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int d = sc.nextInt();
      
      int x = (a+1)*d;
      int y = (d+1)*a;
      int w = Math.max(x,y);
      
      System.out.println(w);


    }
}