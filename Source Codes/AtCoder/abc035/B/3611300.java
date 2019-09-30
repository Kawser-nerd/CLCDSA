import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String s=sc.next();
		int[] coord=new int[2];	//x,y
		coord[0]=0; coord[1]=0;
		int ques=0;			//???
		int operation=sc.nextInt();//1 or 2

		for(int i=0; i<s.length(); i++) {
			if(s.charAt(i)=='L') {
				coord[0]--;
			}

			else if(s.charAt(i)=='R') {
				coord[0]++;
			}

			else if(s.charAt(i)=='U') {
				coord[1]++;
			}

			else if(s.charAt(i)=='D') {
				coord[1]--;
			}
			else if(s.charAt(i)=='?') {
				ques++;
			}
		}

		if(operation==1) {
			System.out.println(Math.abs(coord[0])+Math.abs(coord[1])+ques);
		}
		else if(operation==2) {
			if(s.length()>ques) {
				if(Math.abs(coord[0])+Math.abs(coord[1])-ques<0) {
					System.out.println((ques-Math.abs(coord[0])+Math.abs(coord[1]))%2);
				}
				else {
					System.out.println(Math.abs(coord[0])+Math.abs(coord[1])-ques);
				}
			}
			else {
				System.out.println(ques%2);
			}
		}
	}
}