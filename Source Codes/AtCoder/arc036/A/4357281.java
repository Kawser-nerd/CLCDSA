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
        int n=sc.nextInt(),k=sc.nextInt();
        int r=0;
        int[] t=new int[n+1];
        for (int i = 1; i <= n; i++) {
            t[i]=sc.nextInt();
        }
        for (int i = 1; i <= n; i++) {
            r+=t[i];
            if(i<3)continue;
            if(r<k){
                out.println(i);
                exit(0);
            }
            r-=t[i-2];
        }
        out.println(-1);
    }
}