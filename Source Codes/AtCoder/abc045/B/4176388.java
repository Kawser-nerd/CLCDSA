import java.util.Scanner;
public class Main {
	public static void main(String[] args) throws Exception{
		Scanner scan=new Scanner(System.in);
		String A=scan.next();
		String B=scan.next();
		String C=scan.next();
		int ac=0,bc=0,cc=0,c=0;
		for(;;) {
			if(c==0) {
				ac++;
				if(ac==A.length()+1) {
					System.out.println("A");
					break;
				}
				switch(A.charAt(ac-1)) {
				case 'a':c=0;break;
				case 'b':c=1;break;
				case 'c':c=2;break;
				}
			}if(c==1) {
				bc++;
				if(bc==B.length()+1) {
					System.out.println("B");
					break;
				}
				switch(B.charAt(bc-1)) {
				case 'a':c=0;break;
				case 'b':c=1;break;
				case 'c':c=2;break;
				}
			}if(c==2) {
				cc++;
				if(cc==C.length()+1) {
					System.out.println("C");
					break;
				}
				switch(C.charAt(cc-1)) {
				case 'a':c=0;break;
				case 'b':c=1;break;
				case 'c':c=2;break;
				}
			}
		}
	}
}