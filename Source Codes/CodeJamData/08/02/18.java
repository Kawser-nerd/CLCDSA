package train;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
import java.util.StringTokenizer;

public class TimeTable {
	public static void main(String[] args) 
	{
		TimeTable t = new TimeTable();
		t.solve();
	}
	public TimeTable()
	{
		
	}
	public void solve()
	{
		String filePath = "B-large.in";
		String fileOutput = "B-small.out";
		Scanner scan = null;
		PrintWriter writer = null;
		try
		{
			File file = new File(filePath);
			scan = new Scanner(file);
			writer = new PrintWriter(new File(fileOutput));
		}
		catch(FileNotFoundException e )
		{
			e.printStackTrace();
			return;
		}
		int numOfTest = scan.nextInt();
		scan.nextLine();
		int numOfLeave,numOfRestTime,numOfArrive;
		TimeUnit[] timeColA,timeColB;
		for(int i = 0;i< numOfTest;i++)
		{
			numOfRestTime = scan.nextInt();
			scan.nextLine();
			numOfArrive = scan.nextInt();
			numOfLeave = scan.nextInt();
			scan.nextLine();
			timeColA = new TimeUnit[numOfArrive+numOfLeave];
			timeColB = new TimeUnit[numOfArrive+numOfLeave];
			for(int j = 0;j<numOfArrive;j++)
			{
				int hour1,hour2,minute1,minute2;
				String time = scan.next();
				StringTokenizer s = new StringTokenizer(time,":");
				hour1 = Integer.parseInt(s.nextToken());
				minute1 = Integer.parseInt(s.nextToken());
				
				time = scan.next();
				s = new StringTokenizer(time,":");
				hour2 = Integer.parseInt(s.nextToken());
				minute2 = Integer.parseInt(s.nextToken());
				timeColA[j] = new TimeUnit(hour1*60+minute1,false);
				timeColB[j] = new TimeUnit(hour2*60+minute2+numOfRestTime,true);
			}
			for(int j = 0;j<numOfLeave;j++)
			{
				int hour1,hour2,minute1,minute2;
				String time = scan.next();
				StringTokenizer s = new StringTokenizer(time,":");
				hour1 = Integer.parseInt(s.nextToken());
				minute1 = Integer.parseInt(s.nextToken());
				
				time = scan.next();
				s = new StringTokenizer(time,":");
				hour2 = Integer.parseInt(s.nextToken());
				minute2 = Integer.parseInt(s.nextToken());
				timeColB[j+numOfArrive] = new TimeUnit(hour1*60+minute1,false);
				timeColA[j+numOfArrive] = new TimeUnit(hour2*60+minute2+numOfRestTime,true);
			}
			//sort
			Arrays.sort(timeColA,new CompareTrain());
			Arrays.sort(timeColB,new CompareTrain());
			int busA = 0,busB = 0,leftBusA = 0,leftBusB = 0;
			for(int j = 0;j<numOfLeave+numOfArrive;j++)
			{
				if(timeColA[j].isArrive)
					leftBusA++;
				else
				{
					if(leftBusA == 0)
						busA++;
					else
						leftBusA--;
				}
				if(timeColB[j].isArrive)
					leftBusB++;
				else
				{
					if(leftBusB == 0)
						busB++;
					else
						leftBusB--;
				}
			}
			writer.println("Case #"+(i+1)+": "+busA+" "+busB);
			writer.flush();
			
		}
		scan.close();
		writer.close();
	}
	public class CompareTrain implements Comparator
	{
		public int compare(Object o1,Object o2)
		{
			TimeUnit u1,u2;
			u1 = (TimeUnit)o1;
			u2 = (TimeUnit)o2;
			if(u1.time<u2.time)
				return -1;
			else if(u1.time==u2.time)
			{
				if(u1.isArrive)
					return -1;
				else
					return 1;
			}
			else 
				return 1;
		}
	}
	

}
