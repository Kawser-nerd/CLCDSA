import java.util.*;
import static java.lang.Math.abs;
public class Main{
public static void main(String... args){
Scanner sc=new Scanner(System.in);
int x=sc.nextInt();
int a=sc.nextInt();
int b=sc.nextInt();
if(abs(a-x)<abs(b-x)){
System.out.println("A");
}else{
System.out.println("B");
}
}
}