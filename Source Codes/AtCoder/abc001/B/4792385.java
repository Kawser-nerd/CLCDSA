import java.util.*;
public class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int m = sc.nextInt();
    int vv = 0;
    if( m < 100 ){
      vv = 0;
    } else if( 100 <= m && m <= 5000 ){
      vv = m / 100;
    } else if( 6000 <= m && m <= 30000 ) {
      vv = m / 1000 + 50;
    } else if( 35000 <= m && m <= 70000 ) {
      vv = (m / 1000 - 30) / 5 + 80;
    } else if( 70000 < m ){
      vv = 89;
    }
    System.out.println(String.format("%02d", vv ));
  }
}