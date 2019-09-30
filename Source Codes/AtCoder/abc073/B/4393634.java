import java.util.*;
import static java.lang.Math.abs;
import static java.lang.Math.min;

public class Main{
public static void main(String... argv){
Scanner sc=new Scanner(System.in);
int n=sc.nextInt();
int ans=0;
for(int i=0;i<n;i++){
int l=sc.nextInt();
ans+=sc.nextInt()-l+1;
}
System.out.println(ans);
}
}