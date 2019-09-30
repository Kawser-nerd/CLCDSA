import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long m = sc.nextLong();
        if(n > m){
            long tmp = n;
            n = m;
            m = tmp;
        }

        if(n == 1){
            if(m == 1){
                System.out.println("1");
            }else{
                System.out.println(m-2);
            }
        }else if(n == 2){
            System.out.println("0");
        }else{
            System.out.println((n-2)*(m-2));
        }
    }
}