import java.util.Arrays;
import java.util.Scanner;

class Fountain{
    int X,Y;
    public Fountain(int x,int y){
        X = x;
        Y = y;
    }
}

class Main{

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int x1 = scan.nextInt();
        int y1 = scan.nextInt();
        int x2 = scan.nextInt();
        int y2 = scan.nextInt();

        if(x1>x2){
            int tmp = x1;
            x1 = x2;
            x2 = tmp;
            tmp = y1;
            y1 = y2;
            y2 = tmp;
        }
        int N = scan.nextInt();
        Fountain[] fountain = new Fountain[N];
        for(int i=0;i<N;++i){
        fountain[i] = new Fountain(scan.nextInt(), scan.nextInt());
        }
        if(y1 > y2){
            y1 = (int)1e8 -1 - y1;
            y2 = (int)1e8 -1 - y2;
            for(int i=0;i<N;++i){
                fountain[i].Y = (int)1e8 -1 -fountain[i].Y;
            }
        }
        Arrays.sort(fountain, (a,b) -> a.X-b.X);
        int[] lis = new int[N+1];
        Arrays.fill(lis,Integer.MAX_VALUE);
        lis[0] = 0;
        for(int i=0;i<N;++i){
            if(fountain[i].X < x1 || fountain[i].X > x2)continue;
            if(fountain[i].Y < y1 || fountain[i].Y > y2)continue;
            int left = 0;
            int right = N+1;
            while(true){
                int center = (left+right)/2;
                if(lis[center] > fountain[i].Y){
                    right = center;
                }else{
                    left = center;
                }
                if(right - left ==1)break;
            }
            lis[right] = fountain[i].Y;
        }
        for(int i=N;i>=0;i--){
            if(lis[i] < Integer.MAX_VALUE){
                double ans = (double)(x2 - x1 + y2 - y1) * 100;
                ans -= i*(20 - 5*Math.PI);
                if(i > Math.min(x2-x1,y2-y1)){
                    ans += 10*Math.PI - 20;
                    ans += 20 - 5*Math.PI;
                }
                System.out.println(ans);
                break;
            }
        }



    }
}