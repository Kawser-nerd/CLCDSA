import java.util.*;
public class Main{
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n,a,b;
        n = sc.nextInt();
        a = sc.nextInt();
        b = sc.nextInt();
        int r = 0;
        for(int i = 1; i <= n; i++){
            int c = 0, t = i;
            for(int j = 0; j < 5; j++){
                c = c + (t % 10);
                t = t / 10;
            }
            if(a <= c && c<= b){
                r = r + i;
            }
        }
        System.out.println(r);    
            
    }
}