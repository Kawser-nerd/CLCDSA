/**
 * Created by yoshiwaratomohiro on 2017/06/18.
 */
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int H=scan.nextInt();
        int W=scan.nextInt();
        int h=scan.nextInt();
        int w=scan.nextInt();

        int area=h*w;
        int[][] box = new int[H][W];
        long sum=0;

        int INF=1000000000;

        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(i%h==h-1&&j%w==w-1){
                    box[i][j]=INF*-1;
                }else{
                    if(i%h==0&&j%w==0){
                        box[i][j]=INF-area+1;
                    }else{
                        box[i][j]=1;
                    }

                }
                sum+=box[i][j];

            }

        }
        if(sum>0){
            System.out.println("Yes");
            for(int i=0;i<H;i++){
                for(int j=0;j<W;j++){
                    System.out.print(box[i][j]);
                    if(j<W-1){
                        System.out.print(" ");
                    }
                }
                System.out.println("");
            }

        }else{
            System.out.println("No");
        }
    }
}