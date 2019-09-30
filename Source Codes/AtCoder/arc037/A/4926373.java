import java.util.*;

public class Main {
    public static void main(String[]$) {
        Scanner s=new Scanner(System.in);
        System.out.println(java.util.stream.IntStream.range(0,s.nextInt()).map(m->Math.max(0,80-s.nextInt())).sum());
    }
}