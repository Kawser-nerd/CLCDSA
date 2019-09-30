import java.util.*;
import static java.lang.Math.abs;
public class Main{
public static void main(String... args){
Scanner sc=new Scanner(System.in);
int[] x=new int[]{sc.nextInt(),sc.nextInt(),sc.nextInt(),sc.nextInt()};
int[] tl=new int[101];
for(int i=0;i<101;i++){
if(i>=x[0]&&i<x[1])tl[i]++;
if(i>=x[2]&&i<x[3])tl[i]++;
}
int ans=0;
for(int i=0;i<101;i++){
if(tl[i]==2)ans++;
}
System.out.println(ans);
}
}