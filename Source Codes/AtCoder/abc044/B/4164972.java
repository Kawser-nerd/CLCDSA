import java.util.Scanner;
public class Main {
	public static int f(int a,int b) {
		if(a%2==1||b==1) {
			return 1;
		}
		return 0;
	}
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		String a=scan.next();
		int A=0,B=0,C=0,D=0,E=0,F=0,G=0,H=0,I=0,J=0,K=0,L=0,
				M=0,N=0,O=0,P=0,Q=0,R=0,S=0,T=0,U=0,V=0,W=0,
				X=0,Y=0,Z=0;
		int fig=0;
		for(int i=0;i!=a.length();i++) {
			char b=a.charAt(i);
			switch(b) {
			case 'a':A++;break;
			case 'b':B++;break;
			case 'c':C++;break;
			case 'd':D++;break;
			case 'e':E++;break;
			case 'f':F++;break;
			case 'g':G++;break;
			case 'h':H++;break;
			case 'i':I++;break;
			case 'j':J++;break;
			case 'k':K++;break;
			case 'l':L++;break;
			case 'm':M++;break;
			case 'n':N++;break;
			case 'o':O++;break;
			case 'p':P++;break;
			case 'q':Q++;break;
			case 'r':R++;break;
			case 's':S++;break;
			case 't':T++;break;
			case 'u':U++;break;
			case 'v':V++;break;
			case 'w':W++;break;
			case 'x':X++;break;
			case 'y':Y++;break;
			case 'z':Z++;break;
			}
		}
		fig=f(A,fig);
		fig=f(B,fig);
		fig=f(C,fig);
		fig=f(D,fig);
		fig=f(E,fig);
		fig=f(F,fig);
		fig=f(G,fig);
		fig=f(H,fig);
		fig=f(I,fig);
		fig=f(J,fig);
		fig=f(K,fig);
		fig=f(L,fig);
		fig=f(M,fig);
		fig=f(N,fig);
		fig=f(O,fig);
		fig=f(P,fig);
		fig=f(Q,fig);
		fig=f(R,fig);
		fig=f(S,fig);
		fig=f(T,fig);
		fig=f(U,fig);
		fig=f(V,fig);
		fig=f(W,fig);
		fig=f(X,fig);
		fig=f(T,fig);
		fig=f(Z,fig);
		if(fig==1) {
			System.out.println("No");
		}
		else {
			System.out.println("Yes");
		}
	}
	}