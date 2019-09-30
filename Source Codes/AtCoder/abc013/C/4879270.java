import java.util.*;

public class Main {
    public static void main(String[]$) {
        Scanner scanner = new Scanner(System.in);
        long n=scanner.nextInt(),h=scanner.nextInt(),a=scanner.nextInt(),b=scanner.nextInt(),c=scanner.nextInt(),d=scanner.nextInt(),e=scanner.nextInt();
        java.util.stream.LongStream.rangeClosed(0,n).map(x->a*x+c*((-Math.min(0,h-1+b*x-e*(n-x))+d+e-1)/(d+e))).min().ifPresent(System.out::println);
    }
}