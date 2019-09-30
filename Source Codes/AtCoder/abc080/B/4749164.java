import java.util.*;
public class Main{
    
    public static void main(String[] args){
        int N;
        Scanner Sc = new Scanner(System.in);
        N = Sc.nextInt();
        int t = N, c = 0;
        while(t > 0){
            c+= t % 10;
            t/= 10;
        }
            if(N % c == 0){
                System.out.println("Yes");
            }else{
                System.out.println("No");
            }
    }
}