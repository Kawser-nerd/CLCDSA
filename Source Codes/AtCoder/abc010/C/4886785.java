import java.awt.*;
import java.util.*;
public class Main {
public static void main(String[]$) {
Scanner s=new Scanner(System.in);
Point a=new Point(s.nextInt(),s.nextInt()),b=new Point(s.nextInt(),s.nextInt());
int m=s.nextInt()*s.nextInt();
System.out.println(java.util.stream.Stream.generate(()->new Point(s.nextInt(),s.nextInt())).limit(s.nextInt()).anyMatch(p->a.distance(p)+b.distance(p)<=m)?"YES":"NO");
}
}