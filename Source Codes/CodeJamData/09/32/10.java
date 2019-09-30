/*
PROBLEM: Center of Mass
LANGUAGE: Java
CONTESTANT: Aram Ebtekar
*/

import java.io.*;
import java.util.*;

public class CenterOfMass
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader in = new BufferedReader(new FileReader("B.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B.out")));
		StringTokenizer st;
		
		int T = Integer.parseInt(in.readLine());
		
		for (int caseNum = 1; caseNum <= T; caseNum++)
		{
			int N = Integer.parseInt(in.readLine());
			double xPos = 0.0;
			double yPos = 0.0;
			double zPos = 0.0;
			double xVel = 0.0;
			double yVel = 0.0;
			double zVel = 0.0;
			double time;
			double distance;
			
			for (int i = 0; i < N; i++)
			{
				st = new StringTokenizer(in.readLine());
				xPos += Double.parseDouble(st.nextToken());
				yPos += Double.parseDouble(st.nextToken());
				zPos += Double.parseDouble(st.nextToken());
				xVel += Double.parseDouble(st.nextToken());
				yVel += Double.parseDouble(st.nextToken());
				zVel += Double.parseDouble(st.nextToken());
			}
			
			xPos /= (double) N;
			yPos /= (double) N;
			zPos /= (double) N;
			xVel /= (double) N;
			yVel /= (double) N;
			zVel /= (double) N;
			
			if (xVel == 0.0 && yVel == 0.0 && zVel == 0.0)
			{
				time = 0;
				distance = Math.sqrt(xPos*xPos + yPos*yPos + zPos*zPos);
			}
			else
			{
				time = -(xPos*xVel + yPos*yVel + zPos*zVel)/(xVel*xVel + yVel*yVel + zVel*zVel);
				if (time < 0)
					time = 0;
				double xNew = xPos + time*xVel;
				double yNew = yPos + time*yVel;
				double zNew = zPos + time*zVel;
				distance = Math.sqrt(xNew*xNew + yNew*yNew + zNew*zNew);
			}

			out.println("Case #" + caseNum + ": " + distance + " " + time);
		}
		
		in.close();
		out.close();
		System.exit(0);
	}
}