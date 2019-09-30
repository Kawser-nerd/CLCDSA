import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		long length = sc.nextLong(),yukaSpeed = sc.nextLong(), manSpeed = sc.nextLong(), start = sc.nextLong(), goal = sc.nextLong();
		if(start==goal) {
			System.out.println(0);
		} else if(start < goal) {
			long normalL = goal - start;
			long reverseL = length - goal + start;
			double normalT = (double)normalL / (double)(yukaSpeed + manSpeed);
			double reverseT = manSpeed - yukaSpeed <= 0 ? Double.MAX_VALUE : (double)reverseL / (-yukaSpeed + manSpeed);
			System.out.println(Math.min(normalT, reverseT));
		} else {
			long normalL = length - start + goal;
			long reverseL = start - goal;
			double normalT = (double)normalL / (yukaSpeed + manSpeed);
			double reverseT = -yukaSpeed + manSpeed <= 0 ? Double.MAX_VALUE : (double)reverseL / (-yukaSpeed + manSpeed);
			System.out.println(Math.min(normalT, reverseT));
		}
	}
}