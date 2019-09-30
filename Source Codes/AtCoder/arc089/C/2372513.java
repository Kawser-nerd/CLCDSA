import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int A = scan.nextInt();
        int B = scan.nextInt();
        int[][] d = new int[A+1][B+1];
        for(int i=1;i<=A;++i)for(int j=1;j<=B;++j)d[i][j]=scan.nextInt();

        int[][] f = new int[101][101];
        int[][] dd = new int[A+1][B+1];
        for(int[] array : dd)Arrays.fill(array, 100);
        for(int a=0;a<=100;++a)for(int b=0;b<=100;++b){
            for(int i=1;i<=A;++i)for(int j=1;j<=B;++j)f[a][b] = Math.max(f[a][b] , d[i][j] - a*i - b*j);
        }
        for(int i=1;i<=A;++i)for(int j=1;j<=B;++j){
            for(int a=0;a<101;++a)for(int b=0;b<101;++b)dd[i][j]=Math.min(dd[i][j], f[a][b] + a*i + b*j);
            if(dd[i][j]!=d[i][j]){
                System.out.println("Impossible");
                return;
            }
        }
        System.out.println("Possible");
        System.out.println(202+" "+(200 + 101*101));
        for(int a=0;a<=100;++a)for(int b=0;b<=100;++b)System.out.println((a+1)+" "+(202-b)+" "+f[a][b]);
        for(int i=0;i<100;++i)System.out.println((i+1)+" "+(i+2)+" X");
        for(int i=101;i<201;++i)System.out.println((i+1)+" "+(i+2)+" Y");
        System.out.println("1 202");

    }
}