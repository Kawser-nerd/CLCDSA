import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int output=0;
        int txa=sc.nextInt();
        int tya=sc.nextInt();
        int txb=sc.nextInt();
        int tyb=sc.nextInt();
        int mostMoving=sc.nextInt()*sc.nextInt();
        int tmpX=0;
        int tmpY=0;
        int n=sc.nextInt();
        for(int i=0;i<n;i++){
            tmpX=sc.nextInt();
            tmpY=sc.nextInt();
            if(Math.sqrt((txa-tmpX)*(txa-tmpX)+(tya-tmpY)*(tya-tmpY))+Math.sqrt((txb-tmpX)*(txb-tmpX)+(tyb-tmpY)*(tyb-tmpY))<=mostMoving){
                System.out.println("YES");
                return;
            }
        }
        System.out.println("NO");

}

}