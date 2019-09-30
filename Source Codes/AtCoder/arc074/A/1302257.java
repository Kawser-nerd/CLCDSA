import java.util.Scanner;

public class Main{
  static final long INF = Long.MAX_VALUE / 2;
  static long h, w;

  static final boolean DEBUG = true;

  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    h = sc.nextInt();
    w = sc.nextInt();

    if(h % 3 == 0 || w % 3 == 0){
      System.out.println(0);
      return;
    }

    long min = INF;
    for(long i = 1; i < w; i++){
      long s1 = h * i;
      long s2 = h * ((w - i) / 2);
      long s3 = h * w - (s1 + s2);
      min = Math.min(min, 
          Math.max(s1, Math.max(s2, s3)) - Math.min(s1, Math.min(s2, s3)));
    }
    for(long i = 1; i < h; i++){
      long s1 = w * i;
      long s2 = w * ((h - i) / 2);
      long s3 = h * w - (s1 + s2);
      min = Math.min(min, 
          Math.max(s1, Math.max(s2, s3)) - Math.min(s1, Math.min(s2, s3)));
    }
    for(long i = 1; i < w; i++){
      long s1 = h * i;
      long s2 = (h / 2) * (w - i);
      long s3 = h * w - (s1 + s2);
      min = Math.min(min, 
          Math.max(s1, Math.max(s2, s3)) - Math.min(s1, Math.min(s2, s3)));
    }
    for(long i = 1; i < h; i++){
      long s1 = w * i;
      long s2 = (w / 2) * (h - i);
      long s3 = h * w - (s1 + s2);
      min = Math.min(min, 
          Math.max(s1, Math.max(s2, s3)) - Math.min(s1, Math.min(s2, s3)));
    }

    System.out.println(min);
  }
}