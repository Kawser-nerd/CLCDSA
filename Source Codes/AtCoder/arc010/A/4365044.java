/*
????????????????long???????
???split??contains??????"+"??????????????"\\+"???
???????arr1=arr.clone()
HashSet<>[]???????????????
 */
import java.util.*;
import java.awt.*;
import java.awt.geom.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int n=sc.nextInt(),m=sc.nextInt(),a=sc.nextInt(),b=sc.nextInt();
        int[] c=new int[m+1];
        for (int i = 1; i <= m; i++) {
            c[i]=sc.nextInt();
        }
        for (int i = 1; i <= m; i++) {
            if(n<=a)n+=b;
            n-=c[i];
            if(n<0){
                out.println(i);
                exit(0);
            }
        }
        out.println("complete");
    }
}