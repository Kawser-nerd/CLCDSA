import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int c = sc.nextInt();
    int d = sc.nextInt();
    int e = sc.nextInt();
    int f = sc.nextInt();
    int[] water = new int[(f / 100) + 1];
    int[] sugar = new int[f + 1];

    for(int i = 0; i < water.length; i++) {
      for(int j = 0; j < water.length; j++) {
        if((a * i + b * j) < water.length) water[a * i + b * j] = 1;
      }
    }

    for(int i = 0; i < sugar.length; i++) {
      for(int j = 0; j < sugar.length; j++) {
        if((c * i + d * j) < sugar.length) sugar[c * i + d * j] = 1;
      }
    }

    int satousui = 0;
    int satou = 0;
    double per = -1;

    for(int i = 1; i < water.length; i++) {
      for(int j = 0; j < sugar.length; j++) {
        if((water[i] == 1) && (sugar[j] == 1)) {
          if(100 * i + j <= f) {
            if(j <= e * i) {
              if(((double)j / (double)i) > per) {
                per = (double)j / (double)i;
                satousui = 100 * i + j;
                satou = j;
              }
            }
          }
        }
      }      
    }

    System.out.print(satousui);
    System.out.print(" ");
    System.out.println(satou);
  }
}