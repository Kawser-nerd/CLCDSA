import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int s1 = sc.nextInt();
	double e1 = sc.nextDouble();
	int s2 = sc.nextInt();
	double e2 = sc.nextDouble();
	int s3 = sc.nextInt();
	double e3 = sc.nextDouble();
	double sum = 0;
	sum = s1*0.1*e1+s2*0.1*e2+s3*0.1*e3;
	int ans = (int)sum;
	System.out.println(ans);
    }
}