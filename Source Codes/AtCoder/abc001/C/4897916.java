import java.util.*;

public class Main {
    public static void main(String[]$) {
        Scanner s=new Scanner(System.in);
        int deg=s.nextInt(),dis=(int)Math.round(s.nextInt()/6d);
        System.out.println((dis<=2?"C":(new String[]{"N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW"})[(deg+112)/225%16])+" "+java.util.stream.IntStream.of(2,15,33,54,79,107,138,171,207,244,284,326).reduce(0,(a,b)->dis>b?a+1:a));
    }
}