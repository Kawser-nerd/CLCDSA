import java.util.Scanner;

class Main{
  public static void main(String args[]){
    Scanner scan = new Scanner(System.in);
    double A = scan.nextDouble();
    double B = scan.nextDouble();
    double C = scan.nextDouble();
    double ftmax, ftmin, ftmid, tmin = 0, tmax = 200, tmid = 100;

    for(int i=0; i<100; i++){
      tmid = (tmin + tmax)/2;
      ftmid = A*tmid+B*Math.sin(C*Math.PI*tmid);

      if(ftmid > 100){
        tmax = tmid;
      }else{
        tmin = tmid;
      }

    }
    System.out.println(tmid);
  }
}
// 53 82 49