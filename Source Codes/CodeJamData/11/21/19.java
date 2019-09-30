import java.util.*;
public class RPI {
	public static void main(String[]args)
	{
		Scanner in = new Scanner(System.in);
		int inputs = in.nextInt();
		int caseNum = 1;
		while(inputs-->0)
		{
			int schools = in.nextInt();
			int[][] scores = new int[schools][2];
			String[] list = new String[schools];
			for(int i = 0 ; i < schools; i++)
			{
				int w = 0;
				int l = 0;
				list[i] = in.next();
				String s = list[i];
				for(int j = 0 ;j < s.length();j++)
				{
					if(s.charAt(j)=='0') l++;
					if(s.charAt(j)=='1') w++;
				}
				scores[i][0] = w;
				scores[i][1] = l+w;
				
			}
			double[] OWP = new double[schools];
			for(int i = 0 ; i < schools;i++)
			{
				String s = list[i];
				int count = 0;
				for(int j = 0 ;j < s.length();j++)
				{
					if(s.charAt(j)=='0')
					{
						count++;
						OWP[i] += 1.0 * (scores[j][0]-1) / (scores[j][1]-1);
					}
					if(s.charAt(j)=='1')
					{
						count++;
						OWP[i] += 1.0 * scores[j][0] / (scores[j][1]-1);
					}
				}
				OWP[i]/=count;
			}
			double[] OOWP = new double[schools];
			for(int i = 0 ; i < schools;i++)
			{
				String s = list[i];
				int count = 0;
				for(int j = 0 ;j < s.length();j++)
				{
					if(s.charAt(j)!='.') 
					{
						OOWP[i] += OWP[j];
						count++;
					}
				}
				OOWP[i]/=count;
			}
			double[] RMI = new double[schools];
			for(int i = 0 ; i < schools;i++)
			{
				String s = list[i];
				/*int count = 0;
				for(int j = 0 ;j < s.length();j++)
				{
					count++;
					if(s.charAt(j)!='.') RMI[i] += .5 * OWP[j] + .25*OOWP[j];
				}
				RMI[i] /= count;*/
				RMI[i] += .25 * scores[i][0] / scores[i][1]+.5 * OWP[i] + .25*OOWP[i];
			}
			System.out.println("Case #" + caseNum + ":");
			for(int i = 0;i<schools;i++)
			{
				System.out.printf("%.7f\n",RMI[i]);
			}
			caseNum++;
		}
	}
}
