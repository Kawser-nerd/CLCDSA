import java.util.*;
import static java.lang.Math.abs;
import static java.lang.Math.min;

public class Main{
public static void main(String... argv){
Scanner sc=new Scanner(System.in);
String n=sc.next();
for(char c:n.toCharArray()){
if(c=='9'){
System.out.println("Yes");
return ;
}
}
System.out.println("No");
}
}