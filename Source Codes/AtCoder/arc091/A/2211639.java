import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        long n = Integer.parseInt(sc.next());
        long m = Integer.parseInt(sc.next());

        long ans = 0;
        if(n == 1 && m == 1){
            ans = 1;
        }else if(n == 1 && m > 1){
            ans = m-2;
        }else if(m == 1 && n > 1){
            ans = n-2;
        }else if(n > 1){
            ans = (n-2)*(m-2);
        }
        
        System.out.println(ans);
    }
    
}