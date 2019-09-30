//????
import java.util.*;

class Main{
  public static String outputdeg= null;
  public static int outputdis;

  public static void main(String[] args) {


    Scanner sc= new Scanner(System.in);
    int deg= sc.nextInt()*10;
    int dis= sc.nextInt();

    //deg
    String[] deglist= {"N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW"};
    deg= deg/1125 -1;
    if (0<=deg && deg<30) {
      outputdeg= deglist[deg/2 +1];
    }else{
      outputdeg= deglist[0];
    }

    //dis
    double ren_dis= (double)dis/60;
    ren_dis= Double.parseDouble(String.format("%.1f", ren_dis));
    boolean d= false;
    double[] dislist= {0.2, 1.5, 3.3, 5.4, 7.9, 10.7, 13.8, 17.1, 20.7, 24.4, 28.4, 32.6};
    for (int i=0; i<12; i++) {
      double target= dislist[i];
      if (ren_dis<= target) {
        outputdis= i;
        d= true;
        break;
      }
    }

    if (d==false) {
      outputdis= 12;
    }
    if (outputdis==0) {
      outputdeg= "C";
    }

    //output
    System.out.println(outputdeg + " " + outputdis);

  }
}