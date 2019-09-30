import java.util.*;
public class Main{
    public static void main(String[]$){
        Scanner i=new Scanner(System.in);
        long a=i.nextLong(),b=i.nextLong(),c=i.nextLong(),k=i.nextLong();
        System.out.println(k%2==0?a-b:b-a);
    }
}