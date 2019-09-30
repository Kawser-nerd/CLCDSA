/*
String[]??????????long???????
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
        int d=sc.nextInt();
        int g=sc.nextInt();
        int[] p=new int[d+1];
        int[] c=new int[d+1];
        for (int i = 0; i < d; i++) {
            p[i+1]=sc.nextInt();
            c[i+1]=sc.nextInt();
        }
        int ans=1000000000;
        for (int i = 0; i < (1 << d); i++) {
            int temp=0;
            long score=0;
            for (int j = 0; j < d; j++) {
                if((1&(i>>j))==1) {
                    score += (j + 1) * 100 * p[j + 1] + c[j + 1];
                    temp += p[j + 1];
                }
            }
            if(score>=g){
                ans=min(ans,temp);
            }else {
                for (int j = d-1; j > -1; j--) {
                    if((1&(i>>j))==1)continue;
                    else {
                        for (int k = 1; k < p[j + 1]; k++) {
                            score += (j + 1) * 100;
                            temp += 1;
                            if(score>=g) {
                                ans = min(ans, temp);
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }
        out.println(ans);
    }
}