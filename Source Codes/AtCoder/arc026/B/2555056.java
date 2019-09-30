import java.util.Scanner;
import java.util.Arrays;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        long total = 1;
        for(long i=2; i<=(int)Math.sqrt(N); i++){
            if(N%i==0){
                total=total+i;
                long j = N/i;
                if(j!=i){
                    total=total+j;
                }
                if(total>N){
                    break;
                }
            }
        }
        if(total==1){
            System.out.println("Deficient");
        }else if(total==N){
            System.out.println("Perfect");
        }else if(total<N){
            System.out.println("Deficient");
        }else{
            System.out.println("Abundant");
        }
    }
}