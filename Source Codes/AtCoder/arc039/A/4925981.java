import java.util.*;

public class Main {
    public static void main(String[]$) {
        Scanner s= new Scanner(System.in);
        int a=s.nextInt(),b=s.nextInt();
        java.util.stream.IntStream.of(a%100+900-b,a-b%100-100,a/100*100+a%10+90-b,a-b/100*100-b%10,a/10*10+9-b,a-b/10*10).max().ifPresent(System.out::println);
    }
}