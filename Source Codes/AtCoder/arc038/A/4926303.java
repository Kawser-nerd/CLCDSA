import java.util.*;
import java.util.stream.*;

public class Main {
    public static void main(String[]$) {
        Scanner s=new Scanner(System.in);
        int n=s.nextInt()+1,a[]=IntStream.range(0,n-1).map(i->s.nextInt()).sorted().toArray();
        System.out.println(IntStream.range(0,n/2).map(i->a[i*2+n%2]).sum());
    }
}