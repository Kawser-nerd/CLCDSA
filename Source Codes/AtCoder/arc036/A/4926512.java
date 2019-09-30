import java.util.*;
import java.util.stream.*;

public class Main {
    public static void main(String[]$) {
        Scanner s=new Scanner(System.in);
        int n=s.nextInt(),k=s.nextInt(),t[]=IntStream.range(0,n).map(i->s.nextInt()).toArray();
        System.out.println(IntStream.range(2,n).filter(i->t[i-2]+t[i-1]+t[i]<k).findFirst().orElse(-2)+1);
    }
}