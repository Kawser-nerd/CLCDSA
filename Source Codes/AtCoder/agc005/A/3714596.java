import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String a=sc.next();
		int[] stacks=new int[a.length()];
		int kaisu=0;
		int pointer=0;
		for(int i=0; i<a.length(); i++) {
			if(a.charAt(i)=='S') {
				stacks[pointer]=1;
				pointer++;
			}
			else if(a.charAt(i)=='T') {
				stacks[pointer]=2;
				pointer++;
			}

			if(pointer>=2) {
				if(stacks[pointer-2]==1 && stacks[pointer-1]==2) {
					stacks[pointer-2]=0;
					stacks[pointer-1]=0;
					pointer-=2;
					kaisu++;
				}
			}
		}
		System.out.println((a.length()-kaisu*2));
	}
}