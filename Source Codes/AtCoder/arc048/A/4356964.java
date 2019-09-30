import java.util.*;
public class Main{
    public static void main(String[]$){
        Scanner c=new Scanner(System.in);
        long a=c.nextLong(),b=c.nextLong();
        System.out.println(a*b<0?b-a-1:b-a);
    }
}