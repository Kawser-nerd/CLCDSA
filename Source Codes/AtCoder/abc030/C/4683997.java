import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int x=sc.nextInt();
        int y=sc.nextInt();
        int[] as=new int[n];
        int[] bs=new int[m];
        for(int i=0;i<n;i++){
            as[i]=sc.nextInt();
        }
        for(int i=0;i<m;i++){
            bs[i]=sc.nextInt();
        }
        int takenA=0;
        int takenB=0;
        int time=0;
        int returned=0;
        try{
            while(true){
                while(as[takenA++]<time){}
                time=as[takenA-1]+x;
                while(bs[takenB++]<time){}
                time=bs[takenB-1]+y;
                returned++;
            }
        }catch(ArrayIndexOutOfBoundsException e){
            System.out.println(returned);
        }
    }
}