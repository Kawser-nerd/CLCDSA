import java.util.Scanner; 
public class Main{
  public static void main(String[]args){
    Scanner a = new Scanner(System.in);
    double A =a.nextDouble();
    double B =a.nextDouble();    
    double C =a.nextDouble();
    double D =a.nextDouble();
    double E =a.nextDouble();
    double F =a.nextDouble();
    double S1 =A * D + C * F + E * B - B * C - D * E - F * A;
    double S =Math.abs(S1)/2;
    System.out.println("" + S);
  }
}