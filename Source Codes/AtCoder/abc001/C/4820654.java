import java.util.*;
import java.math.BigDecimal;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        double windDirection = sc.nextDouble() / 10;
        double windDegree = sc.nextDouble();
        double windVelocity = windDegree / 60;
        
        BigDecimal bd = new BigDecimal(String.valueOf(windVelocity)).setScale(1, BigDecimal.ROUND_HALF_UP);
        double averageWindVelocity = bd.doubleValue();
        
        String direction = "";
        String power = "";
        
        // ??
        if(windDirection >= 11.25 && windDirection < 33.75){
            direction = "NNE";
        }else if(windDirection >= 33.75 && windDirection < 56.25){
            direction = "NE";
        }else if(windDirection >= 56.25 && windDirection < 78.75){
            direction = "ENE";
        }else if(windDirection >= 78.75 && windDirection < 101.25){
            direction = "E";
        }else if(windDirection >= 101.25 && windDirection < 123.75){
            direction = "ESE";
        }else if(windDirection >= 123.75 && windDirection < 146.25){
            direction = "SE";
        }else if(windDirection >= 146.25 && windDirection < 168.75){
            direction = "SSE";
        }else if(windDirection >= 168.75 && windDirection < 191.25){
            direction = "S";
        }else if(windDirection >= 191.25 && windDirection < 213.75){
            direction = "SSW";
        }else if(windDirection >= 213.75 && windDirection < 236.25){
            direction = "SW";
        }else if(windDirection >= 236.25 && windDirection < 258.75){
            direction = "WSW";
        }else if(windDirection >= 258.75 && windDirection < 281.25){
            direction = "W";
        }else if(windDirection >= 281.25 && windDirection < 303.75){
            direction = "WNW";
        }else if(windDirection >= 303.75 && windDirection < 326.25){
            direction = "NW";
        }else if(windDirection >= 326.25 && windDirection < 348.75){
            direction = "NNW";
        }else{
            direction = "N";
        }
        
        // ??
        if(averageWindVelocity >= 0.0 && averageWindVelocity <= 0.2){
            power = "0";
        }else if(averageWindVelocity >= 0.3 && averageWindVelocity <= 1.5){
            power = "1";
        }else if(averageWindVelocity >= 1.6 && averageWindVelocity <= 3.3){
            power = "2";
        }else if(averageWindVelocity >= 3.4 && averageWindVelocity <= 5.4){
            power = "3";
        }else if(averageWindVelocity >= 5.5 && averageWindVelocity <= 7.9){
            power = "4";
        }else if(averageWindVelocity >= 8.0 && averageWindVelocity <= 10.7){
            power = "5";
        }else if(averageWindVelocity >= 10.8 && averageWindVelocity <= 13.8){
            power = "6";
        }else if(averageWindVelocity >= 13.9 && averageWindVelocity <= 17.1){
            power = "7";
        }else if(averageWindVelocity >= 17.2 && averageWindVelocity <= 20.7){
            power = "8";
        }else if(averageWindVelocity >= 20.8 && averageWindVelocity <= 24.4){
            power = "9";
        }else if(averageWindVelocity >= 24.5 && averageWindVelocity <= 28.4){
            power = "10";
        }else if(averageWindVelocity >= 28.5 && averageWindVelocity <= 32.6){
            power = "11";
        }else if(averageWindVelocity >= 32.7){
            power = "12";
        }
        
        if(power.equals("0")){
            direction = "C";
        }
        
        System.out.println(direction + " " + power);
    }
}