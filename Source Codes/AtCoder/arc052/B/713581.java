import java.util.Scanner;

class Main{
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);

    int input1 = scan.nextInt();
    int input2 = scan.nextInt();

    int[][] sui = new int[input1][3];
    for(int[] _sui : sui) {
      _sui[0] = scan.nextInt();
      _sui[1] = scan.nextInt();
      _sui[2] = scan.nextInt();
    }
    for(int repeatCount = 0; repeatCount < input2; repeatCount++) {
      int a = scan.nextInt();
      int b = scan.nextInt();

      double answer = 0.0;
      double normal = 0.0;
      double rate1 = 1.0;
      double rate2 = 0.0;

      for(int i = 0; i < sui.length; i++) {
        normal = sui[i][1]*sui[i][1]*sui[i][2]/3.0*Math.PI;
        boolean flag = true;
        if(sui[i][0] <= a && sui[i][0]+sui[i][2] >= a) {
          rate1 = (sui[i][0]+sui[i][2]-a)/(double)sui[i][2];
          flag = false;
        }
        if(sui[i][0]+sui[i][2] >= b && sui[i][0] <= b) {
          rate2 = (sui[i][0]+sui[i][2]-b)/(double)sui[i][2];
          flag = false;
        }
        if(sui[i][0] >= a && sui[i][0]+sui[i][2] <= b) {
          rate1 = 1.0;
          rate2 = 0.0;
          flag = false;
        }
        if(flag) {
          rate1=0.0;
          rate2=0.0;
        }
        answer += normal*(rate1*rate1*rate1-rate2*rate2*rate2);
        rate1=1.0;
        rate2=0.0;
      }
      System.out.println(String.format("%6f",answer));
    }
  }
}