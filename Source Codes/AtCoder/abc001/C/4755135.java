import java.util.*;
import java.math.BigDecimal;

public class Main {
    public static void main(String[] args) throws Exception {
        try (Scanner sc = new Scanner(System.in)) {
            while (sc.hasNextInt()) {
                float Deg = Float.parseFloat(sc.next());
                BigDecimal tmpDis = BigDecimal.valueOf(Float.parseFloat(sc.next()));
                BigDecimal a = BigDecimal.valueOf(60);
                tmpDis = tmpDis.divide(a,1,BigDecimal.ROUND_HALF_UP);
                float Dis = tmpDis.floatValue();
                int W = 12;
                String Dir = "";
                float vec[];
                String vecName[] = {"NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW","N"};
                for(int i=0;i<15;i++){
                  if(Deg < 112.5 || Deg > 112.5 +225 * 15){
                    Dir = "N";
                    break;
                  }else if(Deg >= 112.5 + (225 * i) && Deg < 112.5 + 225 * (i+1) ){
                    Dir = vecName[i];
                    break;
                  }
                }
                float power[] = {0.3f,1.6f,3.4f,5.5f,8.0f,10.8f
                                 ,13.9f,17.2f,20.8f,24.5f,28.5f,32.7f};
                for(int i=0;i<12;i++){
                  if(Dis < power[0]){
                    W = 0;
                    Dir = "C";
                    break;
                  }else if( Dis >= power[11]){
                    W = 12;
                    break;
                  }else if(Dis >= power[i] && Dis < power[i+1]){
                    W = i+1;
                    break;
                  }
                }
                System.out.println(Dir+" "+String.valueOf(W));
            }
        }
    }
}