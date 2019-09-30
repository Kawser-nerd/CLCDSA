import java.util.*;
 
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
       double  x=sc.nextDouble();
       int i =0;
       double sum=0;
       for(i=1;i<=x;i++){
        sum = sum+((i*10000)/x);
       }
       System.out.println(sum);
    }
}