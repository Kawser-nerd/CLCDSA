import java.util.*;
import static java.lang.System.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int[][] c=new int[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                c[i][j]=sc.nextInt();
            }
        }
        int[] a=new int[3];
        int[] b=new int[3];
        for (int i = 0; i <= 100; i++) {
            b[0]=i;
            a[0]=c[0][0]-i;
            a[1]=c[1][0]-i;
            a[2]=c[2][0]-i;
            b[1]=c[0][1]-c[0][0]+i;
            b[2]=c[0][2]-c[0][0]+i;
            int d=0;
            for (int j = 1; j <= 2; j++) {
                for (int k = 1; k <= 2; k++) {
                    if(a[j]+b[k]!=c[j][k])d++;
                }
            }
            if(d==0){
                out.println("Yes");
                break;
            }else if(i==100)out.println("No");
        }
    }
}