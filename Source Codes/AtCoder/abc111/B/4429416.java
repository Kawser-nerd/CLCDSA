import java.util.*;
public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
      
        int a = sc.nextInt();
        int n = 0;
        int ans = 0;
      
        do {
          n++;
          ans = n*100 + n*10 + n;
        } while(a > ans);

          System.out.println(ans);
    }
}