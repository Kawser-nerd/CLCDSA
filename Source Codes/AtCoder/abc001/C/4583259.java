import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.*;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        double deg = sc.nextInt();
        deg /= 10;
        int dis = sc.nextInt();

        String dir;
        if (deg >= 11.25 && deg < 33.75) {
            dir = "NNE";
        } else if(deg >= 33.75 && deg < 56.25) {
            dir = "NE";
        } else if(deg >= 56.25 && deg < 78.75) {
            dir = "ENE";
        } else if(deg >= 78.75 && deg < 101.25) {
            dir = "E";
        } else if(deg >= 101.25 && deg < 123.75) {
            dir = "ESE";
        } else if(deg >= 123.75 && deg < 146.25) {
            dir = "SE";
        } else if(deg >= 146.25 && deg < 168.75) {
            dir = "SSE";
        } else if(deg >= 168.75 && deg < 191.25) {
            dir = "S";
        } else if(deg >= 191.25 && deg < 213.75) {
            dir = "SSW";
        } else if(deg >= 213.75 && deg < 236.25) {
            dir = "SW";
        } else if(deg >= 236.25 && deg < 258.75) {
            dir = "WSW";
        } else if(deg >= 258.75 && deg < 281.25) {
            dir = "W";
        } else if(deg >= 281.25 && deg < 303.75) {
            dir = "WNW";
        } else if(deg >= 303.75 && deg < 326.25) {
            dir = "NW";
        } else if(deg >= 326.25 && deg < 348.75) {
            dir = "NNW";
        } else {
            dir = "N";
        }

        double windSpeed = new BigDecimal(String.valueOf(dis / 60.0)).setScale(1, RoundingMode.HALF_UP).doubleValue();

        int w;

        if (windSpeed >= 0.0 && windSpeed <= 0.2) {
            w = 0;
        } else if (windSpeed >= 0.3 && windSpeed <= 1.5) {
            w = 1;
        } else if (windSpeed >= 1.6 && windSpeed <= 3.3) {
            w = 2;
        } else if (windSpeed >= 3.4 && windSpeed <= 5.4) {
            w = 3;
        } else if (windSpeed >= 5.5 && windSpeed <= 7.9) {
            w = 4;
        } else if (windSpeed >= 8.0 && windSpeed <= 10.7) {
            w = 5;
        } else if (windSpeed >= 10.8 && windSpeed <= 13.8) {
            w = 6;
        } else if (windSpeed >= 13.9 && windSpeed <= 17.1) {
            w = 7;
        } else if (windSpeed >= 17.2 && windSpeed <= 20.7) {
            w = 8;
        } else if (windSpeed >= 20.8 && windSpeed <= 24.4) {
            w = 9;
        } else if (windSpeed >= 24.5 && windSpeed <= 28.4) {
            w = 10;
        } else if (windSpeed >= 28.5 && windSpeed <= 32.6) {
            w = 11;
        } else {
            w = 12;
        }

        if (w == 0) {
            dir = "C";
        }

        System.out.println(dir + " " + w);
    }
}