package r1c;

import java.io.FileReader;
import java.util.Scanner;

public class B {

	/**
	 * @param args
	 */
	
	public static void answer(Scanner in) {
	
		double sx, sy, sz, svx, svy, svz;
		
		sx=0;sy=0;sz=0;svx=0;svy=0;svz=0;
		
		int n = in.nextInt();
		
		for (int i=0; i<n; i++) {
			sx+= in.nextDouble();
			sy+= in.nextDouble();
			sz+= in.nextDouble();
			svx+= in.nextDouble();
			svy+= in.nextDouble();
			svz+= in.nextDouble();
		}
		
		double a,b,c;
		
		a = svx*svx+svy*svy+svz*svz;
		b = 2*(sx*svx+sy*svy+sz*svz);
		c = sx*sx+sy*sy+sz*sz;
		
		double outT;
		
		if (a != 0) {
			outT = -b/(2*a);
			if (outT < 0) {
				outT = 0;
			}
		} else {
			outT = 0;
		}
		
/*		double sqDisc = Math.sqrt(b*b-4*a*c);
		
		t1 = (-b-sqDisc)/(2*a);
		
		if (t1>= 0) {
			outT = t1;
		} else {
			outT = (-b+sqDisc)/(2*a);
		}
		*/
		double outD = a*outT*outT+b*outT+c;
		if (outD<0) {
			outD = 0;
		}
		/*System.out.println(outD);*/
		outD = Math.sqrt(outD)/n;
		
		System.out.println(outD+" "+outT);
		
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			Scanner infile = new Scanner(new FileReader(args[0]));
			
			int t = infile.nextInt();
			infile.nextLine();
						
			for (int i = 0; i<t;i++) {
				
				System.out.print("Case #"+(i+1)+": ");
				answer(infile);
			}
			infile.close();

		} catch (Exception e) 
		{
			System.out.println("Exception occured, stacktrace to follow.");
			e.printStackTrace();
		}

	}

}
