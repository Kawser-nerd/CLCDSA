import java.util.*;

public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt() * 10;
    int M = sc.nextInt();
    
    double m1 = ((double)M / 60) * 10;
    int mps = (int)Math.round(m1);

    String s = "";
    if(mps >=327){
      s = "12";
    }else if(mps >= 285){
      s = "11";
    }else if(mps >= 245){
      s = "10";
    }else if(mps >= 208){
      s = "9";
    }else if(mps >= 172){
      s = "8";
    }else if(mps >= 139){
      s = "7";
    }else if(mps >= 108){
      s = "6";
    }else if(mps >= 80){
      s = "5";
    }else if(mps >= 55){
      s = "4";
    }else if(mps >= 34){
      s = "3";
    }else if(mps >= 16){
      s = "2";
    }else if(mps >= 3){
      s = "1";
    }else{
      s = "0";
    }
    
    String d = "";
    if(s.equals("0")){
      d = "C";
    }else if(N >= 34875){
      d = "N";
    }else if(N >= 32625){
      d = "NNW";
    }else if(N >= 30375){
      d = "NW";
    }else if(N >= 28125){
      d = "WNW";
    }else if(N >= 25875){
      d = "W";
    }else if(N >= 23625){
      d = "WSW";
    }else if(N >= 21375){
      d = "SW";
    }else if(N >= 19125){
      d = "SSW";
    }else if(N >= 16875){
      d = "S";
    }else if(N >= 14625){
      d = "SSE";
    }else if(N >= 12375){
      d = "SE";
    }else if(N >= 10125){
      d = "ESE";
    }else if(N >= 7875){
      d = "E";
    }else if(N >= 5625){
      d = "ENE";
    }else if(N >= 3375){
      d = "NE";
    }else if(N >= 1125){
      d = "NNE";
    }else{
      d = "N";
    }
    System.out.println(d + " " + s);
  }
}