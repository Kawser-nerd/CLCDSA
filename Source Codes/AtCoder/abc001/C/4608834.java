import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int deg=sc.nextInt()*10;
        deg/=1125;
        String outdeg=null;
        String[] degs={"N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW","N"};
        deg++;
        outdeg=degs[deg/2];
        double[] diss={0.3,1.6,3.4,5.5,8.0,10.8,13.9,17.2,20.8,24.5,28.5,32.7};
        for(int i=0;i<diss.length;i++){
            diss[i]=Math.round(diss[i]*60);
        }
        int outdis=0;
        int dis=sc.nextInt();
        for(int i=0;i<diss.length;i++){
            if(diss[i]-3<=dis){
                outdis++;
            }
        }
        System.out.print((outdis==0?"C":outdeg)+" ");
        System.out.println(outdis);
        
    }

}