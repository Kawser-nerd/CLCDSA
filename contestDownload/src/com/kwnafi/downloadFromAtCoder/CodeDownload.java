package com.kwnafi.downloadFromAtCoder;

import com.kwnafi.downloadFromAtCoder.FolderCreation;
import com.kwnafi.downloadFromAtCoder.LinkExtracted;



////1.  Download ATPGrad Contest
////Link: https://atcoder.jp/contests/agc001/submissions?f.Task=agc001_a&f.Language=3016&f.Status=AC&f.User=
//// Language: Java: 3016, Python3: 3023, python2: 3023, C#: 3006, C: 3002, C++: 3005
//// Task


public class CodeDownload {
	
	static String contestLinkHeader = "https://atcoder.jp/contests/";
	static String contestName = "arc";
	static String[] languages = {"3016", "3023", "3006", "3002", "3005"};
	static String[] extensions = {".java", ".py", ".cs", ".c", ".cpp"};
	static String[] questions = {"a","b", "c", "d", "e", "f"};
	static String contestSerial = "";

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		LinkExtracted lk = new LinkExtracted();
		FolderCreation a = new FolderCreation();

		String link;
		
		for(int i = 1; i <= 45; i++)
		{
			if(i < 10) {
				contestSerial = contestName + "00" + String.valueOf(i);
			}
			else if(i >= 10 && i <100)
			{
				contestSerial = contestName + "0" + String.valueOf(i);
			}
			else
			{
				contestSerial = contestName +  String.valueOf(i);
			}
			
			for (int j = 0; j < 6; j++)
			{
				a.dirCreation(contestSerial, questions[j].toUpperCase());
				
				for (int k = 0; k < 5; k++)
				{
					if(i>34)
					{
						 link = contestLinkHeader + contestSerial + '/' + "submissions?f.Task=" + contestSerial + 
							'_' + questions[j] + "&f.Language=" + languages[k] + "&f.Status=AC&f.User=";
					}
					else
					{
						 link = contestLinkHeader + contestSerial + '/' + "submissions?f.Task=" + contestSerial + 
								'_' + String.valueOf(j+1) + "&f.Language=" + languages[k] + "&f.Status=AC&f.User=";
					}
					System.out.println(link);
					//b = (String[])Array lk.LinkExtraction(link);
					lk.LinkExtraction(link);
					lk.CodeDownLoad(contestSerial, questions[j], extensions[k]);	
				}
			}
			
		}
	}
}
