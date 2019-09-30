import java.util.Scanner;

public class Main{
  public static void main(String[]args){
    Scanner a = new Scanner(System.in);
    int Deg = a.nextInt() * 10;
    double Dis = a.nextInt();
    double v1 = Dis/6; 
    int v = (int)Math.floor(v1 + 0.5f);
    String w = "";
    if(0 <= v && v <= 2){
      w = "0";
    }else if(v <= 15){
      w = "1";
    }else if(v <= 33){
      w = "2";
    }else if(v <= 54){
      w = "3";
    }else if(v <= 79){
      w = "4";
    }else if(v <= 107){
      w = "5";
    }else if(v <= 138){
      w = "6";
    }else if(v <= 171){
      w = "7";
    }else if(v <= 207){
      w = "8";
    }else if(v <= 244){
      w = "9";
    }else if(v <= 284){
      w = "10";
    }else if(v <= 326){
      w = "11";
    }else{      
      w = "12";
    }
    
    String Dir = "";
    if(w.equals("0")){
      Dir = "C";
    }else if(0 <= Deg && Deg < 1125 ){
      Dir = "N"; 
    }else if(1125 <= Deg && Deg < 3375){
      Dir = "NNE";
    }else if(Deg < 5625){
      Dir = "NE";
    }else if(Deg < 7875){
      Dir = "ENE";
    }else if(Deg < 10125){
      Dir = "E";
    }else if(Deg < 12375){
      Dir = "ESE";
    }else if(Deg < 14625){
      Dir = "SE";
    }else if(Deg < 16875){
      Dir = "SSE";
    }else if(Deg < 19125){
      Dir = "S";
    }else if(Deg < 21375){
      Dir = "SSW";
    }else if(Deg < 23625){
      Dir = "SW";
    }else if(Deg < 25875){
      Dir = "WSW";
    }else if(Deg < 28125){
      Dir = "W";
    }else if(Deg < 30375){
      Dir = "WNW";
    }else if(Deg < 32625){
      Dir = "NW";
    }else if(Deg < 34875){
      Dir = "NNW";
    }else{
      Dir = "N";
    }
    System.out.println(""+ Dir + " " + w);
  }
}