import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int H = sc.nextInt();
        int W = sc.nextInt();
        String[] dic = new String[H];
        for(int i=0;i<H;i++) dic[i]=sc.next();
        int end = -1;
        for(int i=0;i<H;i++){
            int left = 0;
            while(left<H&&dic[i].charAt(left)=='.') left++;
            if(end>left){
                System.out.println("Impossible");
                System.exit(0);
            }
            end = W-1;
            while(end>=0&&dic[i].charAt(end)=='.') end--;
        }
        System.out.println("Possible");
    }
}